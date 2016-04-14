// pipe_popen_pclose.cpp

// Demonstrates the high-level functions popen and pclose

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fp;
	char buff[BUFSIZ + 1]; // BUFSIZ defined in stdio.h
	int nCharsRead;
	memset(buff, '\0', sizeof(buff));
	fp = popen("ls -Fla", "r");
	if (fp != NULL)
	{
		nCharsRead = fread(buff, sizeof(char), BUFSIZ, fp);
		while (nCharsRead > 0)
		{
			buff[nCharsRead - 1] = '\0';
			printf("Buffer size is %d:\n %s\n", BUFSIZ, buff);
			nCharsRead = fread(buff, sizeof(char), BUFSIZ, fp);
		}	
		pclose(fp);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
