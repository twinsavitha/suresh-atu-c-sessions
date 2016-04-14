// signalFromKeyboard.cpp

// Demonstrates the registration of signal and signal handler
// Signal is generated from the keyboard on press of ctrl+c

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <iostream>
using std::cout;

// Define the handler function to be called when ctrl-c (SIGINT) signal is sent to process
void sigint_handler(int signum)
{
   // Write the code here that this handler is supposed to do
   printf("Signal %d caught.\n", signum);
   cout << "Exiting the program.\n";   
   // Terminate program
   exit(signum);
}

int main()
{
   // Register the signal we are interested in and its signal handler
   signal(SIGINT, sigint_handler);

   while(true)
   {
	  cout << "Writing to the console...\n";
      sleep(1);
   }
   return(EXIT_SUCCESS);
}          
