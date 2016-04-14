#include <iostream>

typedef double Type;

template<typename Type>
Type min(Type a, Type b)
{
	// temp will have the type of the template parameter Type
	// not that of the global typedef
	Type temp = (a<b ? a : b);
	return temp;
}

int main()
{
	int x = 5, y = 6, z;
	z = min(x, y);
	std::cout << "Min of x and y is " << z << std::endl;
	return(0);
}
