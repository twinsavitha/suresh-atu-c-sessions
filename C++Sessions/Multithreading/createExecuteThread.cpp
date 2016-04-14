// createExecuteThread.cpp

// Demonstrates the creation and execution of a thread

// Compilation steps:
// 1. Include pthread.h
// 2. g++ -D_REENTRANT createExecuteThread.cpp -lpthread -o creatExecThread

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h> // needs to be included for threads

// Forward declaration of the function executed when the thread is run
void *threadRoutine(void *arg);

char strMsg[] = "Hello World"; // Additional info to thread
int *pParam2Thread = new int(13);
int main()
{
	int res;
	pthread_t thread1;
	void *threadResult; // Result info returned by joining the thread

	// 1. Create a thread.
	res = pthread_create(&thread1, NULL, threadRoutine, (void *)pParam2Thread);
	if (res != 0)
	{
		perror("Failed creating thread\n");
		exit(EXIT_FAILURE);
	}
	printf("Main thread: New thread invoked. Let the new thread run\n");

	// 2. Parent thread waits for the child thread's execution
	res = pthread_join(thread1, &threadResult);
	if (res != 0)
	{
		perror("pthread_join failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Back to Main thread\n");
	printf("Main thread: New thread returned - [%s]\n", (char *)threadResult);
	printf("Main thread: Value after modification by the new thread is %d\n", *pParam2Thread);
	exit(EXIT_SUCCESS);
}

// The function that runs when the thread is in execution
void *threadRoutine(void *arg)
{
	printf("New thread: Running the routine (function)\n");
	int *pArg = reinterpret_cast<int *>(arg);
	printf("New thread: Parameter passed is : %d\n", *pArg);
	sleep(1);
	printf("New thread: Changing the value of the parameter to 23\n");
	*pArg = 23;
	pthread_exit(reinterpret_cast<void *>(const_cast<char *>("Modified the argument passed, check it.")));
}
