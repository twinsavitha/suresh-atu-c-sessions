// exec functions overwrite the process image with the new program
#include <stdio.h>
#include <iostream>
using std::cout;

int main()
{
	execl("/usr/bin/wc", "wc", "-l", "-c", "/home/159231/sessions/Daemons/temp.txt", NULL);
	return(0);
}
