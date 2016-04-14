// signalFromProgram.cpp

// Demonstrates the registration of signal and signal handler
// Signal is generated programmatically

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <iostream>
using std::cout;

pid_t g_pid; // global variable to hold the pid of the child process

// Define the handler function to be called when signal (SIGALRM) is sent to process
void sigalrm_handler(int signum)
{
   // Write the code here that this handler is supposed to do
   printf("Signal %d caught.\n", signum);
   cout << "Exiting the program.\n";   
   // Terminate program
	if (kill(g_pid, SIGTERM) == 0)
	{
		cout << "5 seconds passed, child process is terminated\n";
    }
}

int main()
{
   // Register the signal we are interested in and its signal handler
   signal(SIGALRM, sigalrm_handler);

   	switch(g_pid = fork())
	{
	case -1:cout << "Error forking the process\n";
	case  0:sleep(1);
			execl("/usr/bin/tail", "tail", "-f", "./log.txt", NULL);
			 break;
	default:
			alarm(5); 
			pause();
	}

   return(EXIT_SUCCESS);
}          
