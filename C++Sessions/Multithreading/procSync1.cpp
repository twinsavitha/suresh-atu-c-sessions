#include <iostream>
#include <fcntl.h>
#include "TCS_Header.h"

using std::cout;

int main()
{
	int fileDesc;
	fileDesc = TCS::CLock::getLock();
	if (fileDesc != -1)
	{
		cout << "Got the lock - Process1\n";
		sleep(30);
		TCS::CLock::releaseLock();	
	}
	else
	{
		cout << "Failed getting the lock - P1\n";
	}

	close(fileDesc);

	return(0);
}
