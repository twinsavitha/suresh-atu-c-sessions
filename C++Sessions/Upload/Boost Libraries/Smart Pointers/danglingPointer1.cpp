// danglingPointer1.cpp

// Demonstrates the concept of dangling pointers
#include <iostream>
using std::cout;

int main()
{
	int *pInt1 = new int(17);
	int *pInt2 = pInt1;
	cout << *pInt1 << '\n';
	cout << *pInt2 << '\n';
	delete pInt1;  // releases the memory held; pInt2 now becomes a dangling pointer
	delete pInt2;

	return(0);
}
