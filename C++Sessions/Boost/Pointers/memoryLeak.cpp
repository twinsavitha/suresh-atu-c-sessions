// memoryLeak.cpp

// Demonstrates the memory leak
#include <iostream>

const int ARRAY_SIZE = 10;

// Global pointer to verify the content of the memory leaked
int *g_pIntArray = NULL;

int memLeak()
{
	int *pIntArray = new int[ARRAY_SIZE];

	g_pIntArray = pIntArray;

	for (int nIdx = 0; nIdx < ARRAY_SIZE; ++nIdx)
	{
		pIntArray[nIdx] = nIdx + 10;
	}

	for (int nIdx = 0; nIdx < ARRAY_SIZE; nIdx++)
	{
		std::cout << pIntArray[nIdx] << '\n';
	}

	// Variable 'pIntArray' goes out of scope here; results in a memory leak
	return(0);
}

int main()
{
	memLeak();

	// UNCOMMENT
	///*
	// Verify that the memory is not released
	std::cout << "!!!Memory leak!!!\n";
	for (int nIdx = 0; nIdx < ARRAY_SIZE; nIdx++)
	{
		std::cout << g_pIntArray[nIdx] << '\n';
	}
	//*/
	return(0);
}
