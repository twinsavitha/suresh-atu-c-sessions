// Child process is same as the parent except for the PID.
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <iostream>
using std::cout;

const int PATH_LENGTH = 30;

int main(void)
{
	pid_t pid;
	int x = 100;
	char newdir[PATH_LENGTH + 1];

	getcwd(newdir, PATH_LENGTH);
	cout << "Before forking -- Current directory: " << newdir << "\n";

	pid = fork();
	switch (pid)
	{
	case -1:
		perror("fork");
		exit(1);
	case 0:
		cout << "CHILD -- Inherited value of x: " << x << "\n";
		x = 200;
		cout << "CHILD -- Changed value of x: " << x << "\n";
		cout << "CHILD -- Inherited value of PATH: " << getenv("PATH") << "\n";
		setenv("PATH", ".", 1);
		cout << "CHILD -- New value of PATH: " << getenv("PATH") << "\n";
		if (chdir("/etc") != -1)
		{
			getcwd(newdir, PATH_LENGTH);
			cout << "CHILD -- Current directory changed to: " << newdir << "\n";
		}
		break;
		exit(0);
	default:
		sleep(2);
		getcwd(newdir, PATH_LENGTH);
		cout << "PARENT -- Value of x after change by child: " << x << "\n";
		cout << "PARENT -- Current directory is still : " << newdir << "\n";
		cout << "PARENT -- Value of PATH is unchanged: " << getenv("PATH") << "\n";
		exit(0);
	}
	return(0);
}
