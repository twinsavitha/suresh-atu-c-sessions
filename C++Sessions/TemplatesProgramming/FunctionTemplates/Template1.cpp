#include <iostream>

template <class Type>
Type min(Type a, Type b)
{
	return(a<b ? a : b);
}

int main()
{
	// int min(int, int)
	std::cout << "Minimum of 10 and 20 is " << min(10, 20) << std::endl;

	// double min(double, double)
	std::cout << "Minimum of 10.0 and 20.0 is " << min(10.0, 20.0) << std::endl;
	return(0);
}
