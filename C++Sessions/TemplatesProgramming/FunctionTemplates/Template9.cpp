#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

// Overloading function templates
template <typename T>
T printValue(T t1)
{
	cout << "In printValue #1 with value " << t1 << endl;
	return(t1);
}

template <typename T, typename U>
void printValue(T t1, U u1)
{
	cout << "In printValue #2 with values " << t1 << '\t' << u1 << endl;
}

int main()
{
	printValue('a');
	printValue(23, 'x');

	return(0);
}
