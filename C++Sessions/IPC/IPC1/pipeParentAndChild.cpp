// pipeParentAndChild.cpp

// Demonstrates pipe between parent and a child
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using std::cout;

const int MAX_SIZE = 48;
int main()
{
	int nCharsWritten, fd[2];
	char buf[MAX_SIZE];

	if (pipe(fd) < 0)
		exit(1);

	switch(fork())
	{
	case -1: cout << "Error in forking\n";exit(1);
	case  0: nCharsWritten = read(fd[0], buf, MAX_SIZE);
			 write(STDOUT_FILENO, buf, nCharsWritten);
			 break;
	default: write(fd[1], "Message from parent 2 child through a pipe\n", sizeof("Message from parent 2 child through a pipe\n"));
	}
	return(0);
}
