// auto_ptr_exception.cpp

// Demonstrates the deallocation of objects
// by auto_ptr class template on exception

#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::auto_ptr;
using std::string;

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

void exceptionalFn() throw(int, string)
{
	auto_ptr<Test> p_auto_Test(new Test(17));
	try
	{
		throw(7);
		// throw(string("Catch me!!!");
	}
	// UNCOMMENT 
	///*
	catch(int nExObj)
	{
		cout << "In exceptionalFn(): Caught the exception object for numerals\n";
	}
	//*/
	catch(string str)
	{
		cout << "In exceptionalFn(): Caught the exception object for strings\n";
	}
	cout << "Exiting the exceptionalFn()\n";
}

int main()
{
	try
	{
		exceptionalFn();
	}
	catch(int nExObj)
	{
		cout << "In main: Caught the exception object for numerals\n";
	}
	return(0);
}
