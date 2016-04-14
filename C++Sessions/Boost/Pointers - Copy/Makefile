EXE = memLeak
OBJ = memoryLeak.o
CC = g++ -Wall -g
FLAGS = 

$(EXE) : $(OBJ)
	$(CC) -o $(EXE) $(OBJ)

memoryLeak.o : memoryLeak.cpp
	$(CC) -c memoryLeak.cpp

.PHONY : clean
clean :
	rm $(EXE) $(OBJ)
