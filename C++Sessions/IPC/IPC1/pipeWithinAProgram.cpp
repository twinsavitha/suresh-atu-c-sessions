// pipeWithinAProgram.cpp

// Demonstrates communication within a program using pipe

#include <iostream>
#include <unistd.h>

using std::cout;

const int MAX_SIZE = 50;
int main()
{
	int nCharsWritten, fd[2];
	char buf[MAX_SIZE];

	pipe(fd); // takes file descriptors as argument
	// fd[0] is the end for input  i.e., end for reading from input
	// fd[1] is the end for output i.e., end for writing to output
	write(fd[1], "Hello World!\n", 13);
	nCharsWritten = read(fd[0], buf, 100);
	write(STDOUT_FILENO, buf, nCharsWritten); // STDOUT_FILENO defined in unistd.h
	return(0);
}
