// memoryCorruption.cpp

// Demonstrates the memory corruption
#include <iostream>

const int ARRAY_SIZE = 5;
const int IDX_OUT_OF_BOUNDS = ARRAY_SIZE * 2;

// Array1 overwrites the memory of Array2; leading to memory corruption
int memCorruption()
{
	int *pIntArray1 = new int[ARRAY_SIZE];
	int *pIntArray2 = new int[ARRAY_SIZE];

	for (int nIdx = 0; nIdx < ARRAY_SIZE; ++nIdx)
	{
		pIntArray2[nIdx] = nIdx + 23;
	}
	
	std::cout << "Array2 Before memory corruption\n";
	for (int nIdx = 0; nIdx < ARRAY_SIZE; nIdx++)
	{
		std::cout << pIntArray2[nIdx] << '\n';
	}

	for (int nIdx = 0; nIdx < IDX_OUT_OF_BOUNDS; ++nIdx)
	{
		pIntArray1[nIdx] = nIdx + 10;  // Writing data beyond the ARRAY_SIZE
	}

	std::cout << "Array1\n";
	for (int nIdx = 0; nIdx < IDX_OUT_OF_BOUNDS; nIdx++)
	{
		std::cout << pIntArray1[nIdx] << '\n';
	}
	
	std::cout << "Array2 After memory corruption\n";
	for (int nIdx = 0; nIdx < ARRAY_SIZE; nIdx++)
	{
		std::cout << pIntArray2[nIdx] << '\n';
	}

	return(0);
}

int main()
{
	memCorruption();

	return(0);
}
