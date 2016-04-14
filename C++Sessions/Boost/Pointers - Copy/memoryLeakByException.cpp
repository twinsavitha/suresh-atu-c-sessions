// memoryLeakByException.cpp

// Demonstrates the memory leak by exception
#include <iostream>

// Code flow
/*
main()
  |--func1() - Exception is handled here
	|--exceptionFn() - Exception is thrown here
*/

// Globals
const int ARRAY_SIZE = 10;
const int IDX_OUT_OF_BOUND = ARRAY_SIZE + 1;

enum bounds {WITHIN_BOUND, OUT_OF_BOUND};

// Global pointer to verify the content of the memory leaked
int *g_pIntArray = NULL;

// Throws an exception on accessing index out of bounds
int exceptionFn() throw(bounds)
{
	int *pIntArray = new int[ARRAY_SIZE];

	g_pIntArray = pIntArray;

	for (int nIdx = 0; nIdx < ARRAY_SIZE; ++nIdx)
	{
		pIntArray[nIdx] = nIdx + 10;
	}
	
	for (int nIdx = 0; nIdx < IDX_OUT_OF_BOUND; nIdx++)
	{
		// throw an exception on index out of bounds
		if (nIdx == IDX_OUT_OF_BOUND-1)
		{
			bounds exObj(OUT_OF_BOUND);
			throw exObj;
		}
		std::cout << pIntArray[nIdx] << '\n';
	}

	delete []pIntArray;
	return(0);
}

void func1()
{
	try
	{
		exceptionFn();
	}
	catch (bounds){ std::cout << "Caught an exception\n"; }
}

int main()
{
	func1();

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
