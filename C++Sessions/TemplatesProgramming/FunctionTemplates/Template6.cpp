#include <iostream>
using std::cout;
using std::endl;

template <typename T>
T confused(T, T)
{
	T unResolved = 32;
	return(unResolved);
}

int main()
{
	unsigned int uIntVal;

	// cannot instantiate as T is not resolved to either int or unsigned int
	//cout << confused(23, uIntVal);
	cout << confused<unsigned int>(23, uIntVal);
	return(0);
}
