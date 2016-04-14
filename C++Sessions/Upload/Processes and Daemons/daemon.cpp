// Demonstrates the steps to write a daemon

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE *fp = NULL;
	pid_t pid = 0;
	pid_t sid = 0;

	// Create child process
	pid = fork();

	if (pid < 0) // fork() failed and returned -1
	{
		printf("Fork failed!\n");
		exit(1);
	}
	if (pid > 0) // parent; kill it
	{
		printf("PID of child process %d \n", pid);
		// return success in exit status
		exit(0);
	}	

	//unmask the file mode
	umask(0);
	//set new session
	sid = setsid();
	if (sid < 0)
	{
		// Return failure
		exit(1);
	}
	
	// Change the current working directory to root.
	chdir("/");

	// Close stdin. stdout and stderr
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	// Now the (child) process is a daemon
	// Open a log file in write mode.
	fp = fopen ("LogFile.txt", "w+");
	while (1)
	{
		//Dont block context switches, let the process sleep for some time
		sleep(1);
		fprintf(fp, "Writing to log file...\n");
		fflush(fp);

		// Now write the code for what this daemon is supposed to do
	}
	fclose(fp);
	return(0);
}
