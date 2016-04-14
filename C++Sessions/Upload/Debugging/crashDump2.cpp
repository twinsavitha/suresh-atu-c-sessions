#include <iostream>
using namespace std;

void setValue(int *pVal, int Value)
{
	*pVal = Value;
}

int main()
{
	int num;
	setValue(&num, 10);
	cout << num << endl;

	int *pNum;
	setValue(pNum, 20);
	cout << *pNum << endl;

	return(0);
}
