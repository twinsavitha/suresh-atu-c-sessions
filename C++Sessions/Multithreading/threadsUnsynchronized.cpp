// threadsUnsynchronized.cpp

// Demonstrates the execution of threads unsynchronized

// Compilation steps:
// 1. Include pthread.h
// 2. g++ -D_REENTRANT threadsUnsynchronized.cpp -lpthread -o threadsUnsync 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h> // needs to be included for threads

// Forward declaration of the function executed when the thread is run
void *threadRoutine(void *);

// global variable
int g_nCtr = 0;

int main()
{
	int res;
	pthread_t thread1;

	// 1. Create a thread.
	res = pthread_create(&thread1, NULL, threadRoutine, NULL);
	if (res != 0)
	{
		perror("Failed creating thread\n");
		exit(EXIT_FAILURE);
	}
	while (g_nCtr < 10)
	{
		printf("Main thread: %d\n", g_nCtr);
		g_nCtr++;
	}
}

void *threadRoutine(void *)
{
	while (g_nCtr < 10)
	{
		printf("Child thread: %d\n", g_nCtr);
		g_nCtr++;
	}
}

