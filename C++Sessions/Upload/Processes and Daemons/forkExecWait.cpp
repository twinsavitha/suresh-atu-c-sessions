// Demonstrates the use of fork, exec and wait

#include <stdio.h>
#include <wait.h>
#include <cstdlib>
#include <iostream>
using std::cout;

int main(int argc, char *argv[])
{
	int exitstatus;

	switch(fork())
	{
	case 0:
		if (execv(argv[1], &argv[2]) < 0)
		{
			fprintf(stderr, "execv error\n");
			exit(200);
		}
	default:
		wait(&exitstatus);
		fprintf(stderr, "New process's exit status: %d\n", WEXITSTATUS(exitstatus));
		exit(0);
	}	
	return(0);
}
