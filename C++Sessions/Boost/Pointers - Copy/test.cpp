#include <iostream>
using namespace std;

int main()
{
	int i = 10;
	int *p = &i;
	cout << "Value of i is " << *p << '\n';
	delete [] p;
	return(0);
}
