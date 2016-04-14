#include <iostream>
using std::cout;
using std::endl;

template <typename T>
T confused(T, T)
{
	T unResolved;
	return(unResolved);
}

int main()
{
	unsigned int uIntVal;

	// cannot instantiate as T is not resolved to either int or unsigned int
	confused(23, uIntVal);
	return(0);
}
