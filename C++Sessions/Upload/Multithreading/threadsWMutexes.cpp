// threadsWMutexes.cpp

// Demonstrates the synchronization of threads with mutexes

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int g_Value = 0;  // global variable modified by the threads
pthread_mutex_t mutexObj;  // mutex object to control the access

void* threadFunction(void *arg)
{
	for (int nIdx = 0; nIdx < 100; nIdx++)
	{
		pthread_mutex_lock(&mutexObj);  // Locks the code
		int tmpVal = g_Value;
		tmpVal++;
		g_Value = tmpVal;
		printf("%d\t", g_Value);
		pthread_mutex_unlock(&mutexObj);  // Unlocks the code
	}
}

int main()
{
	pthread_t thread1, thread2;
	int retVal;
	void *thread1RetVal;
	void *thread2RetVal;
	
	retVal = pthread_mutex_init(&mutexObj, NULL);  // Initialize the mutex
	if (retVal != 0)
	{
		fprintf(stderr, "Mutex initialization failed\n");
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
	pthread_mutex_destroy(&mutexObj);  //  destroy the mutex

	return(EXIT_SUCCESS);
}
