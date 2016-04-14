// scoped_ptr.cpp

// Demonstrates the usage of the class template scoped_ptr<T>
// Compile as : g++ -Wall -g -I"/home/159231/boost_1_45_0" scoped_ptr.cpp
#include <boost/scoped_ptr.hpp>
#include <iostream>

using boost::scoped_ptr;
using std::cout;

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
	// 1. Initialization of a scoped_ptr object
	scoped_ptr<int> pInt1(new int(17));

	// 2. operator*() returns a reference to the object pointed by the stored pointer
	cout << "The value held by pInt1 is " << *pInt1 << '\n';
	
	*pInt1 = 23;
	cout << "The value now held by pInt1 is " << *pInt1 << '\n';

	// 3. With class objects
	scoped_ptr<Test> pTestObj1(new Test(13));
	pTestObj1->value();
	
	return(0);
}
