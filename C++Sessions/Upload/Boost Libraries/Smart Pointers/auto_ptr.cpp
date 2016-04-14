// auto_ptr.cpp

// Demonstrates the features of auto_ptr class template
#include <iostream>
#include <memory>

using std::cout;
using std::auto_ptr;

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
	// 1. Initialization of an auto_ptr object
	auto_ptr<int> p_auto_int1(new int(23));
	cout << "The value held by the auto pointer 1 is " << *p_auto_int1 << '\n';
	
	// 2. The auto_ptr object is initialized with a value of 0, by default
	auto_ptr<int> p_auto_int2;
	if (p_auto_int2.get() == 0) // get() returns the underlying pointer
	{
		p_auto_int2.reset(p_auto_int1.release()); // reset() sets the underlying pointer; release() relinquishes the ownership;
		cout << "The value held by the auto pointer 2 is " << *p_auto_int2 << '\n';		
	}

	// 3. auto_ptr objects refering the objects of a class
	auto_ptr<Test> p_auto_Test1(new Test());
	p_auto_Test1->value();

	auto_ptr<Test> p_auto_Test2(new Test(43));
	p_auto_Test2->value();
	
	// Change of ownership
	p_auto_Test2 = p_auto_Test1; // Calls the destructor on Test2 object
	p_auto_Test1.reset(0);  // p_auto_Test1 is no longer owning the object

	
	//p_auto_Test2.reset(p_auto_Test1.release()); // Same as above two lines
	p_auto_Test2->value();

	// The pointer objects go out of scope here, objects on free store are deallocated
	return(0);
}
