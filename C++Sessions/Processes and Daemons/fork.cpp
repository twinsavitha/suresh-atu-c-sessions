// fork creates a new process
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <iostream>
using std::cout;

int main()
{
	pid_t pid;
	cout << "Before forking.\n";
	pid = fork();

	if (pid > 0) // We are in parent
	{
		sleep(1);
		printf("PARENT -- PID: %d PPID: %d, CHILD PID: %d\n",
					getpid(), getppid(), pid);
	}
	else if (pid == 0) // We are in child
	{
		printf("CHILD -- PID: %d PPID: %d\n", getpid(), getppid());
	}
	else // fork() failed, returned -1
	{
		cout << "Error in forking.\n";
		exit(1);
	}
	cout << "Both processes write from here\n";
	exit(0);
}
