// consumer.cpp

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
	int open_mode = O_RDONLY;
	char buffer[MAX_SIZE];
	memset(buffer, '\0', sizeof(buffer));
	printf("Opening FIFO %s in read mode\n", FIFO_FILE);
	pipe_fd = open(FIFO_FILE, open_mode);
	if (pipe_fd != -1)
	{
		read(pipe_fd, buffer, MAX_SIZE);
		printf("%s", buffer);
		(void)close(pipe_fd);
	}
	else
	{
		exit(EXIT_FAILURE);
	}
	printf("Finished reading.\n");
	exit(EXIT_SUCCESS);
}
