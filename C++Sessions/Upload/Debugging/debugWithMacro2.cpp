// Demonstrates the use of macros for debugging.
// Compile this program with -DDEBUG option

#include <iostream>
using std::cout;
using std::cin;

const int MAX_INDEX = 10;
int main()
{
	for (int nIdx = 0; nIdx < MAX_INDEX; nIdx++)
	{
		if (nIdx = 5)
		{
			#ifdef DEBUG
				int nWait;
				cout << "Index value is " << nIdx << '\n';
				cin >> nWait;
			#endif
			cout << "Value is " << nIdx << '\n';
		}
	}
	return(0);
}

