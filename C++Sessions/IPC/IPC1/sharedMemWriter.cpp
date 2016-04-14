// sharedMemWriter.cpp

// Demonstrates the sharing of memory by two processes
// The Writer writes to the memory and the other process (Reader) reads it.

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>

// Include the header in both Writer and Reader programs
#include "sharedMemStdHdr.h"

int main()
{
	bool bWriting = true; // Set it to false when writing is done
	sharedMemBlock *pSharedMemBlock = NULL;
	char buffer[BUFSIZ];
	int shmid;
	
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
	printf("Memory attached.\n");

	printf("Enter text to write to memory (end with an *):\n ");
	while (bWriting)
	{
		while(pSharedMemBlock->bAccess == true)
		{
			sleep(1);
		}
		fgets(buffer, BUFSIZ, stdin);
		strncpy(pSharedMemBlock->chText, buffer, SHM_SIZE);
		pSharedMemBlock->bAccess = true;
		if (strncmp(buffer, "*", 1) == 0)
		{
			bWriting = false;
		}
	}

	// Detach the memory
	if (shmdt(pSharedMemBlock) == -1)
	{
		printf("shmdt: Failed detaching the memory\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
