// Incomplete behavioral model of MIPS pipeline

module mipspipe(clock);
   // in_out
   input clock;

   // Instruction opcodes
   parameter LW = 6'b100011, SW = 6'b101011, BEQ = 6'b000100, nop = 32'b00000_100000, ALUop = 6'b0; 
   reg [31:0] PC, // Program counter
		  Regs[0:31],  // Register file
			  IMemory[0:1023], DMemory[0:1023], // Instruction and data memories
              IFIDIR, IDEXA, IDEXB, IDEXIR, EXMEMIR, EXMEMB, // pipeline latches
              EXMEMALUOut, MEMWBValue, MEMWBIR; // pipeline latches

   wire [4:0] IDEXrs, IDEXrt, EXMEMrd, MEMWBrd, MEMWBrt; // fields of pipeline latches
   wire [5:0] EXMEMop, MEMWBop, IDEXop; // opcodes
   wire [31:0] Ain, Bin; // ALU inputs

   // Define fields of pipeline latches
   assign IDEXrs = IDEXIR[25:21]; // rs field
   assign IDEXrt = IDEXIR[20:16]; // rt field
   assign EXMEMrd = EXMEMIR[15:11]; // rd field
   assign MEMWBrd = MEMWBIR[15:11]; // rd field
   assign MEMWBrt = MEMWBIR[20:16]; // rt field -- for loads
   assign EXMEMop = EXMEMIR[31:26]; // opcode
   assign MEMWBop = MEMWBIR[31:26]; // opcode
   assign IDEXop = IDEXIR[31:26]; // opcode

   // Inputs to the ALU come directly from the ID/EX pipeline latches
   assign Ain = IDEXA;
   assign Bin = IDEXB;
   reg [5:0] i; //used to initialize registers
   reg [10:0] j,k; //used to initialize registers

   initial begin
      PC = 0;
      IFIDIR = nop; 
      IDEXIR = nop; 
      EXMEMIR = nop; 
      MEMWBIR = nop; // no-ops placed in pipeline latches
      // test some instructions
      for (i=0;i<=31;i=i+1) Regs[i] = i; // initialize registers
      IMemory[0] = 32'h00412820; // ADD OPCODE: 000000 00010 00001 00101 00000 100000
      IMemory[1] = nop;
      IMemory[2] = nop;
      IMemory[3] = nop;
      IMemory[4] = 32'h8CA30004; // First LW:   100011 00101 00011 00000 00000 000100
      IMemory[5] = 32'h8C420000; // Second LW:  100011 00010 00010 00000 00000 000000
      IMemory[6] = nop;
      IMemory[7] = nop;
      IMemory[8] = 32'h00A31825; // OR OPCODE:  000000 00101 00011 00011 00000 100101
      IMemory[9] = nop;
      IMemory[10] =nop;
      IMemory[11] = nop;
      IMemory[12] = 32'hACA30000; // SW:         101011 00101 00011 00000 00000 000000
      for (j=13;j<=1023;j=j+1) IMemory[j] = nop;
      DMemory[0] = 32'h00000000;
      DMemory[1] = 32'hffffffff;
      for (k=2;k<=1023;k=k+1) DMemory[k] = 0;
   end
   
   always @ (posedge clock) 
   begin
      // FETCH: Fetch instruction & update PC
      IFIDIR <= IMemory[PC>>2];
	  PC <= PC + 4;
    
      // DECODE: Read registers 
      IDEXA <= Regs[IFIDIR[25:21]]; 
      IDEXB <= Regs[IFIDIR[20:16]]; // get two registers
      
	  IDEXIR <= IFIDIR; // pass along IR
      
      // EX: Address calculation or ALU operation
      if ((IDEXop==LW) |(IDEXop==SW)) // address calculation
         EXMEMALUOut <= IDEXA +{{16{IDEXIR[15]}}, IDEXIR[15:0]};
      else if (IDEXop==ALUop) begin // ALU operation
         case (IDEXIR[5:0]) // R-type instruction
           32: EXMEMALUOut <= Ain + Bin; // add operation
           37: EXMEMALUOut <= Ain | Bin; //or
           default: ; // other R-type operations [to be implemented]
         endcase
      end
   
      EXMEMIR <= IDEXIR; EXMEMB <= IDEXB; //pass along the IR & B
   
      // MEM 
      if (EXMEMop==ALUop) MEMWBValue <= EXMEMALUOut; //pass along ALU result
      else if (EXMEMop == LW) MEMWBValue <= DMemory[EXMEMALUOut>>2]; // load
      else if (EXMEMop == SW) DMemory[EXMEMALUOut>>2] <=EXMEMB; // store
   
      MEMWBIR <= EXMEMIR; //pass along IR
   
      // WB 
      if ((MEMWBop==ALUop) & (MEMWBrd != 0)) // update registers if ALU operation and destination not 0
		Regs[MEMWBrd] <= MEMWBValue; // ALU operation
      else if ((MEMWBop == LW)& (MEMWBrt != 0)) // Update registers if load and destination not 0
		Regs[MEMWBrt] <= MEMWBValue;
    end

endmodule
