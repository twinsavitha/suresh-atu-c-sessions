// scoped_array.cpp

// Demonstrates the usage of the class template scoped_array<T>
// Compile as : g++ -Wall -g -I"/home/159231/boost_1_45_0" scoped_array.cpp
#include <boost/scoped_array.hpp>
#include <iostream>

using boost::scoped_array;
using std::cout;

const unsigned int ARRAY_SIZE = 5;
const ssize_t INIT_VALUE = 13;

class Test
{
public:
    Test() : value_(29) {}
    Test(int val) : value_(val) {}
    ~Test() { cout << "Class Test destructor\n"; }
    void value() { cout << "The value is " << value_ << '\n'; }
private:
    int value_;
};

int main()
{
	// 1. Initialization of a scoped_array object
	scoped_array<int> pIntArray(new int[ARRAY_SIZE]);

	// 2. operator[] is defined to return the element at the specified index
	for (size_t nIdx = 0; nIdx < ARRAY_SIZE; nIdx++)
	{
		pIntArray[nIdx] = INIT_VALUE + nIdx;
	}

	for (size_t nIdx = 0; nIdx < ARRAY_SIZE; nIdx++)
	{
		cout << pIntArray[nIdx] << '\t';
	}
	cout << '\n';

	// 3. scoped_array for objects of a class
	scoped_array<Test> pTestArray(new Test[ARRAY_SIZE]);

	// 4. Refer to the individual elements of the array using operator[]
	pTestArray[3].value();

	// 5. Refer to a different array
	pTestArray.reset(new Test[2]);
	cout << "Reinitialized the scoped array pointer to a different array\n";

	return(0);
}
