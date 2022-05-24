// Incomplete behavioral model of MIPS pipeline

module mipspipe_mp2 (clock);
  // in_out
  input clock;

  // Instruction opcodes
  parameter LW = 6'b100011, SW = 6'b101011, BEQ = 6'b000100, nop = 32'b00000_100000, ALUop = 6'b0;
  reg [31:0] PC, Regs[0:31], IMemory[0:1023], DMemory[0:1023], // instruction and data memories
             IFIDIR, IDEXA, IDEXB, IDEXIR, EXMEMIR, EXMEMB, // pipeline latches
             EXMEMALUOut, MEMWBValue, MEMWBIR;

  wire [4:0] IDEXrs, IDEXrt, EXMEMrd, MEMWBrd, MEMWBrt, IFIDrt, IFIDrs; // hold register fields
  wire [5:0] EXMEMop, MEMWBop, IDEXop, IFIDop; // hold opcodes
  wire [31:0] Ain, Bin; // ALU inputs

  // declare the bypass signals
  wire bypassAfromMEM, bypassAfromALUinWB, bypassBfromMEM, bypassBfromALUinWB, bypassAfromLWinWB, bypassBfromLWinWB, bypassIDEXAfromWB, bypassIDEXBfromWB, STALL;

   // Define fields of pipeline latches
   assign IDEXrs = IDEXIR[25:21]; // rs field
   assign IDEXrt = IDEXIR[20:16]; // rt field
   assign EXMEMrd = EXMEMIR[15:11]; // rd field
   assign MEMWBrd = MEMWBIR[15:11]; // rd field
   assign MEMWBrt = MEMWBIR[20:16]; // rt field -- for loads
   assign EXMEMop = EXMEMIR[31:26]; // opcode
   assign MEMWBop = MEMWBIR[31:26]; // opcode
   assign IDEXop = IDEXIR[31:26]; // opcode
   assign IFIDrs = IFIDIR[25:21];
   assign IFIDrt = IFIDIR[20:16];
   assign IFIDop = IFIDIR[31:26]; 


  // The bypass to input A from the MEM stage for an ALU operation
  assign bypassAfromMEM = (IDEXrs == EXMEMrd) & (IDEXrs!=0) & (EXMEMop==ALUop);
  // The bypass to input B from the MEM stage for an ALU operation
  assign bypassBfromMEM = 0;
  // The bypass to input A from the WB stage for an ALU operation
  assign bypassAfromALUinWB = 0;
  // The bypass to input B from the WB stage for an ALU operation
  assign bypassBfromALUinWB = 0; 
  // The bypass to input A from the WB stage for an LW operation
  assign bypassAfromLWinWB = (IDEXrs == MEMWBIR[20:16]) & (IDEXrs!=0) & (MEMWBop==LW);
  // The bypass to input B from the WB stage for an LW operation
  assign bypassBfromLWinWB = 0;
  //Stall to bypass A or B if need b (I'm not sorry)
  assign bypassIDEXAfromWB = ((MEMWBIR != nop) & (IFIDIR != nop) & (IFIDrs == MEMWBrt) & (MEMWBop == LW)) | 
    ((MEMWBop == ALUop) & (MEMWBrd == IFIDrs)); 
  assign bypassIDEXBfromWB = ((MEMWBIR != nop) & (IFIDIR != nop) & (IFIDrt == MEMWBrt) & (MEMWBop == LW)) | 
    ((MEMWBop == ALUop) & (MEMWBrd == IFIDrt)); 
  // The A input to the ALU is bypassed from MEM if there is a bypass there,
  // Otherwise from WB if there is a bypass there, and otherwise comes from the IDEX register
  assign Ain = bypassAfromMEM? EXMEMALUOut : (bypassAfromALUinWB | bypassAfromLWinWB)? MEMWBValue : IDEXA;

  // The B input to the ALU is bypassed from MEM if there is a bypass there,
  // Otherwise from WB if there is a bypass there, and otherwise comes from the IDEX register
  // Ripped off of above just replacing "A" with "B"
  assign Bin = bypassBfromMEM? EXMEMALUOut : (bypassBfromALUinWB | bypassBfromLWinWB)? MEMWBValue : IDEXB;


  reg [5:0] i; // used to initialize latches
  reg [10:0] j,k; // used to initialize memories

  // Make the Big Stall
  assign STALL = (IDEXop == LW) && 
    //All of this is anded with the above (Lisp would be proud)
    (((IFIDop == LW) && (IFIDrs == IDEXrt)) |
    ((IFIDop == ALUop) && ((IFIDrs == IDEXrt) | (IFIDrt == IDEXrt))) |
    ((IFIDop == SW) && ((IFIDrs == IDEXrt) | (IFIDrt == IDEXrt))));
  
  initial begin
    PC = 0;
    IFIDIR = nop; 
    IDEXIR = nop; 
    EXMEMIR = nop; 
    MEMWBIR = nop; // no-ops in pipeline latches
  
    for (i = 0;i<=31;i = i+1) Regs[i] = i; // initialize latches
  
    IMemory[0] = 32'h00412820; // ADD $5, $2, $1
    IMemory[1] = 32'h8ca30004; // LW $3, 4($5)
    IMemory[2] = 32'haca70005; // SW $7, 5($5)
    // Hazard 1: ADD might not have written to $5 before SW reads from $5 (Type 2: Read after Write)
    IMemory[3] = 32'h00602020; // ADD $4, $3, $0
    // Hazard 2: ADD might read $3 before LW writes to $3 (Type 3: Write after read)
    IMemory[4] = 32'h01093020; // ADD $6, $8, $9
    IMemory[5] = 32'hac06000c; // SW $6, $12($0)
    // Hazard 3: ADD and SW are trying to access the same register (Type 1: Write after Write)
    IMemory[6] = 32'h00c05020; // ADD $10, $6, $0
    // Hazard 4: ADD reads from $6 and is written to (twice) immediately beforehand (Type 2: Read after Write)
    IMemory[7] = 32'h8c0b0010; // LW $11, 32($0)
    IMemory[8] = 32'h00000020; // ADD $0, $0, $0
    IMemory[9] = 32'h002b6020; // ADD $12, $1, $11
    // Hazard 5: LW might not have written to $11 before the last ADD reads from $11 (Type 2: Read after Write)
    for (j=10; j<=1023; j=j+1) IMemory[j] = nop;
    
    DMemory[0] = 32'h00000000;
    DMemory[1] = 32'hffffffff;
    DMemory[2] = 32'h00000000;
    DMemory[3] = 32'h00000000;
    DMemory[4] = 32'hfffffffe;
    for (k=5; k<=1023; k=k+1) DMemory[k] = 0;
  end

  always @ (posedge clock) begin
    if (~STALL) begin
	  // FETCH: Fetch instruction & update PC
      IFIDIR <= IMemory[PC>>2];
      PC <= PC + 4;

      // DECODE: Read registers
      if (~bypassIDEXAfromWB) begin
        IDEXA <= Regs[IFIDIR[25:21]]; 
      end 
       else begin
          IDEXA <= MEMWBValue;
      end

      if (~bypassIDEXBfromWB) begin
        IDEXB <= Regs[IFIDIR[20:16]];
      end 
       else begin
        IDEXB <= MEMWBValue;
      end
        IDEXIR <= IFIDIR; 
    end 
     else begin //IF (STALL)
        IDEXIR <= nop;
    end

    // EX: Address calculation or ALU operation
    if ((IDEXop==LW) |(IDEXop==SW)) // address calculation & copy B
       EXMEMALUOut <= Ain +{{16{IDEXIR[15]}}, IDEXIR[15:0]};
    else if (IDEXop==ALUop) begin
       case (IDEXIR[5:0]) // R-type instruction
         32: EXMEMALUOut <= Ain + Bin; // add operation
         default: ; // other R-type operations: subtract, SLT, etc.
       endcase
    end
   
    EXMEMIR <= IDEXIR; 
    EXMEMB <= Bin; // pass along the IR & B register
   
    // MEM
    if (EXMEMop==ALUop) MEMWBValue <= EXMEMALUOut; // pass along ALU result
    else if (EXMEMop == LW) MEMWBValue <= DMemory[EXMEMALUOut>>2];
    else if (EXMEMop == SW) DMemory[EXMEMALUOut>>2] <=EXMEMB; // store
   
    MEMWBIR <= EXMEMIR; // pass along IR
   
    // WB 
    if ((MEMWBop==ALUop) & (MEMWBrd != 0)) // update latches if ALU operation and destination not 0
    Regs[MEMWBrd] <= MEMWBValue; // ALU operation
    else if ((MEMWBop == LW)& (MEMWBrt != 0)) // Update latches if load and destination not 0
    Regs[MEMWBrt] <= MEMWBValue;
  end

endmodule

