// shared_array.cpp

// Demonstrates the usage of the class template shared_array<T>
// Compile as : g++ -Wall -g -I"/home/159231/boost_1_45_0" shared_array.cpp
#include <boost/shared_array.hpp>
#include <iostream>
#include <stdio.h>

using boost::shared_array;
using std::cout;

const int ARRAY_SIZE = 5;

class Test
{
public:
    Test() : value_(0) {}
    Test(int val) : value_(val) {}
    ~Test() { cout << "Class Test destructor\n"; }
    void value() { cout << "The value is " << value_ << '\n'; }
private:
    int value_;
};


int main()
{
	// 1. Initialization of a shared_array object
	shared_array<int> pIntArr1(new int[ARRAY_SIZE]);
	pIntArr1[2] = 29;
	cout << "pIntArr1: ";
	for (int nIdx = 0; nIdx < ARRAY_SIZE; nIdx++)
	{
		cout << pIntArr1[nIdx] << '\t';
	}
	cout << '\n';
	
	// 2. pIntArr1 and pIntArr2 both share the ownership
	shared_array<int> pIntArr2(pIntArr1);
	cout << "pIntArr2: ";
	for (int nIdx = 0; nIdx < ARRAY_SIZE; nIdx++)
	{
		cout << pIntArr2[nIdx] << '\t';
	}
	cout << '\n';

	// Array of objects of the class Test
	shared_array<Test> pTestArr1(new Test[3]);

	// pTestArr1 & 2, both share the ownership
	shared_array<Test> pTestArr2(pTestArr1);
	
	return(0);
}
