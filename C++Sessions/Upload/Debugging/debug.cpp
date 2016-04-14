#include <iostream>
using std::cout;

const int MAX_SIZE = 5;

void swap(int &rVal1, int &rVal2)
{
	int temp = rVal1;
	rVal1 = rVal2;
	rVal2 = temp;
}

void sort(int nArray[])
{
	for (int x = 0; x < MAX_SIZE-1; x++)
	{
		for (int y = 0; y < MAX_SIZE-1-x; y++)
		{
			if (nArray[y] > nArray[y+1])
			{
				swap(nArray[y], nArray[y+1]);
			}
		}
	}
}

int main()
{
	int nArray[MAX_SIZE] = { 32, 52, 12, 42, 22 };
	sort(nArray);
	for (int nIdx = 0; nIdx < MAX_SIZE; nIdx++)
	{
		cout << nArray[nIdx] << '\t';
	}
	return(0);
}
