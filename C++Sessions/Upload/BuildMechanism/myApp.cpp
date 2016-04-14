#include <iostream>
#include <cstdlib>
#include "twice.h"
#include "thrice.h"

int
main()
{
	int a = 5;
	std::cout << "Twice the value is " << twoTimes(a) << std::endl;
	std::cout << "Thrice the value is " << threeTimes(a) << std::endl;
	return(EXIT_SUCCESS);
}
