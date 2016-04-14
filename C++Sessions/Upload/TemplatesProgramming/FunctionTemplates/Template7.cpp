#include <iostream>
using std::cout;
using std::endl;

template <typename T, typename U>
T confused(T, U)
{
	T unResolved = 32;
	return(unResolved);
}

int main()
{
	int mVal = 16;
	int nVal = 18;
	// Explicitly specify the template argument as like default arguments
	// Function instantiated as confused(unsigned int, int);
	cout << confused<unsigned int>(mVal, nVal);
	return(0);
}
