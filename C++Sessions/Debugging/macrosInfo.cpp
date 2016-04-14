// Demonstrates the use of macros defined by the preprocessor
// Compile it with -DDEBUG
#include <iostream>
using std::cout;

int main()
{
#ifdef DEBUG
	cout << "Program built at " << __TIME__ << " on " << __DATE__ << '\n';
	cout << "This is line " << __LINE__ << " from file " << __FILE__ << '\n';
#endif
	cout << "Hello World\n";
	return(0);
}
