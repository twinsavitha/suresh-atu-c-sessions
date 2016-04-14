#include <iostream>
#include <fcntl.h>
#include "TCS_Header.h"

using std::cout;

int main()
{
	ssize_t fileDesc;
	fileDesc = TCS::CLock::getLock();
	if (fileDesc != -1)
	{
		cout << "Got the lock - Process2\n";
		TCS::CLock::releaseLock();
	}
	else
	{
		cout << "Failed getting the lock - P2\n";
	}

	close(fileDesc);

	return(0);
}
