// Demonstrates the wait() function
// Parent waits for the child to die.

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <iostream>
using std::cout;

int main(int argc, char *argv[])
{
	int fd;
	int exitstatus;
	int exitval = 10;
	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd, "Original process writes\n", 24);

	switch (fork())
	{
	case 0:   // child
		write(fd, "Child writes\n", 13);
		close(fd);
		cout << "CHILD: Terminating with exit value " << exitval << "\n";
		exit(exitval);
	default:  // parent
		wait(&exitstatus);
		cout << "PARENT: Child terminated with exit value " << WEXITSTATUS(exitstatus) << "\n";
		write(fd, "Parent writes\n", 14);
		exit(20);
	}
	return(0);
}
