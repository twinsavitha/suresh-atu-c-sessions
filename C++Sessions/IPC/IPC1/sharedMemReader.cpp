// sharedMemReader.cpp

// Demonstrates the sharing of memory by two processes
// The Reader reads the memory while the Writer writes to it.

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>

// Include the header in both Reader and Writer programs
#include "sharedMemStdHdr.h"

int main()
{
	bool bReading = true; // Set it to false when reading is done
	sharedMemBlock *pSharedMemBlock = NULL;
	int shmid;
	srand((unsigned int)getpid());

	// Allocate and get the memory
	shmid = shmget(KEY_SHM, sizeof(sharedMemBlock), 0666 | IPC_CREAT);
	if (shmid == -1)
	{
		printf("shmget: Failed getting the memory\n");
		exit(EXIT_FAILURE);
	}

	// Attach the memory
	pSharedMemBlock = (sharedMemBlock *)shmat(shmid, (void *)0, 0);
	if (pSharedMemBlock == (void *)-1)
	{
		printf("shmat: Failed attaching the memory\n");
		exit(EXIT_FAILURE);
	}
	printf("Memory attached\n");
	pSharedMemBlock->bAccess = false;

	while (bReading)
	{
		if (pSharedMemBlock->bAccess)
		{
			printf("%s", pSharedMemBlock->chText);
			sleep(1);
			pSharedMemBlock->bAccess = false;
			if (strncmp(pSharedMemBlock->chText, "*", 1) == 0)
			{
				bReading = false;
			}
		}	
	}

	// Detach the memory
	if (shmdt(pSharedMemBlock) == -1)
	{
		printf("shmdt: Failed detaching the memory\n");
		exit(EXIT_FAILURE);
	}

	// Delete the memory
	if (shmctl(shmid, IPC_RMID, 0) == -1)
	{
		printf("shmctl: Failed deleting the memory\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
