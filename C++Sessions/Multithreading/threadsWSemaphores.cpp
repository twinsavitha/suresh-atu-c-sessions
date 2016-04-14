// threadsWSemaphores.cpp

// Demonstrates the synchronization of threads with semaphores

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>  // include for semaphores

int g_Value = 0;  // global variable modified by the threads
sem_t sema4;    // semaphore object controling the global variable

void* threadFunction(void *arg)
{
	for (int nIdx = 0; nIdx < 100; nIdx++)
	{
		sem_wait(&sema4);   // Locks the semaphore
		int tmpVal = g_Value;
		tmpVal++;
		g_Value = tmpVal;
		printf("%d\t", g_Value);
		sem_post(&sema4);   // Unlocks the semaphore
	}
}

int main()
{
	pthread_t thread1, thread2;
	int retVal;
	void *thread1RetVal;
	void *thread2RetVal;
	
	retVal = sem_init(&sema4, 0, 1); // Initializes the semaphore
	//sem_post(&sema4);
	if (retVal != 0)
	{
		fprintf(stderr, "Semaphore initialization failed\n");
	    exit(EXIT_FAILURE);
	}

	retVal = pthread_create(&thread1, NULL, threadFunction, NULL);
	if (retVal != 0)
	{
		fprintf(stderr, "Thread1 creation failed\n");
		exit(EXIT_FAILURE);
	}

	retVal = pthread_create(&thread2, NULL, threadFunction, NULL);
	if (retVal != 0)
	{
		fprintf(stderr, "Thread2 creation failed\n");
		exit(EXIT_FAILURE);
	}
	retVal = pthread_join(thread1, &thread1RetVal);
	retVal = pthread_join(thread2, &thread2RetVal);
	sem_destroy(&sema4);

	return(EXIT_SUCCESS);
}
