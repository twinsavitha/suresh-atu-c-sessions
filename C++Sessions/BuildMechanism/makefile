# Demonstrates variables and macros
CC = g++

EXE = myApp

SRC = myApp.cpp \
	  twice.cpp \
	  thrice.cpp

OBJ = myApp.o \
	  twice.o \
	  thrice.o

.PHONY: all

# Specify all the targets that needs built
#all: myApp
all		 : $(EXE)
build	 : $(EXE)
rebuild	 : clean build

$(EXE): $(OBJ)
	$(CC) -o $@ $(OBJ)
	
myApp.o: myApp.cpp
	$(CC) -c myApp.cpp

twice.o: twice.cpp 
	$(CC) -c twice.cpp

thrice.o: thrice.cpp
	$(CC) -c thrice.cpp

clean:
	rm *.o $(EXE)
