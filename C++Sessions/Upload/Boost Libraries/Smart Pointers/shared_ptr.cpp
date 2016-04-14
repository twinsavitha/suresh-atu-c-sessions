// shared_ptr.cpp

// Demonstrates the usage of the class template shared_ptr<T>
// Compile as : g++ -Wall -g -I"/home/159231/boost_1_45_0" shared_ptr.cpp
#include <boost/shared_ptr.hpp>
#include <iostream>
#include <stdio.h>

using boost::shared_ptr;
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

class FileCloser
{
public:
	void operator()(FILE *fp)
	{
		cout << "Closing the file.\n";
		fclose(fp);
	}
};

int main()
{
	// 1. Initialization of a shared_ptr object
	shared_ptr<Test> pTestObj1(new Test(19));
	pTestObj1->value();

	// 2. pTestObj1 & 2, both share the ownership
	shared_ptr<Test> pTestObj2(pTestObj1);
	pTestObj2->value();

	// 3. TestObj1(19) is not deleted as pTestObj2 is still refering it
	pTestObj1.reset(new Test(23));

	cout << '\n';
	cout << "Obj1: "; pTestObj1->value();
	cout << "Obj2: "; pTestObj2->value();

	// 4. We can specify the method for destruction as the second
	//    argument while creating the shared pointer to the object
	FileCloser fc;
	shared_ptr<FILE> pFileStruct(fopen("test", "w"), fc);

	return(0);
}
