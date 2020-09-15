CC=gcc
CFLAGS=-I./include
OBJ=main.o name.o address.o major.o
EXE=w2.out

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)
clean:
	rm *.o $(EXE)
run:
	./$(EXE)