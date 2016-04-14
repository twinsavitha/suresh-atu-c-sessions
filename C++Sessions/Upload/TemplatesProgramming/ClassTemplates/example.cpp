#include <iostream>
using namespace std;

int square (int z);

int main()
{
	int y = square(5);
	cout << y << endl;
}

int square(int x)
{
	return(x*x);
}	
