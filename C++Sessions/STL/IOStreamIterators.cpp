/*
 * IOStreamIterators.cpp
 *
 *  Created on: 31-Dec-2013
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
	cout << "Please enter two numbers: ";
	std::istream_iterator<int> inputInt(cin);    // Associate the iterator with the standard input
	int n1 = *inputInt;
	++inputInt;
	int n2 = *inputInt;
	std::ostream_iterator<int> outputInt(cout);  // Associate the iterator with the standard output
	cout << "The sum is ";
	*outputInt = n1+n2;
	cout << endl;

	return(0);
}
