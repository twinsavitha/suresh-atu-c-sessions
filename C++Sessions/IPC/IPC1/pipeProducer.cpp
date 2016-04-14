// producer.cpp

// Demonstrates the usage of pipe
// for communication between unrelated programs

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

const char FIFO_FILE[] = "/tmp/myFIFO";
const int MAX_SIZE = 100;

int main()
{
	int pipe_fd;
	int res;
	int open_mode = O_WRONLY;

	char buffer[MAX_SIZE] = "Data from producer to consumer.\n"; 
	
	if (access(FIFO_FILE, F_OK) == -1)
	{
		res = mkfifo(FIFO_FILE, 0777);
		
		if (res != 0)
		{
			fprintf(stderr, "Could not create fifo %s\n", FIFO_FILE);
			exit(EXIT_FAILURE);
		}
	}	

	printf("Opening FIFO %s in write mode\n", FIFO_FILE);
	printf("Writing the string [Data from producer to consumer.]\n");
	pipe_fd = open(FIFO_FILE, open_mode);
	if (pipe_fd != -1)
	{
		res = write(pipe_fd, buffer, MAX_SIZE);
		if (res == -1)
		{
			fprintf(stderr, "Error writing to pipe\n");
			exit(EXIT_FAILURE);
		}
		(void)close(pipe_fd);
	}
	else
	{
		exit(EXIT_FAILURE);
	}
	printf("Completed writing data\n");
	exit(EXIT_SUCCESS);
}
