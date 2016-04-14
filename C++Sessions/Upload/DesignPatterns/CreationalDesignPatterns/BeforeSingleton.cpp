// Prior to the Singleton design pattern

#include <iostream>
using std::cout;
using std::endl;

class GlobalClass
{
public:
	GlobalClass(int val = 0) : value_(val) {}
	int getValue() { return(value_); }
	void setValue(int val) { value_ = val; }
private:
	int value_;
};

// Default initialization
GlobalClass *gp_GlobalClassObj;

// Two functions that refer the same object of the GlobalClass
void function1()
{
	if (!gp_GlobalClassObj)
	{
		gp_GlobalClassObj = new GlobalClass;
	}
	gp_GlobalClassObj->setValue(10);
	cout << "function1(): Value is " << gp_GlobalClassObj->getValue() << '\n';
}

void function2()
{
	if (!gp_GlobalClassObj)
	{
		gp_GlobalClassObj = new GlobalClass;
	}
	gp_GlobalClassObj->setValue(20);
	cout << "function2(): Value is " << gp_GlobalClassObj->getValue() << '\n';
}

int main()
{
	if (!gp_GlobalClassObj)
	{
		gp_GlobalClassObj = new GlobalClass;
	}
	cout << "main(): Value is " << gp_GlobalClassObj->getValue() << '\n';
	function1();
	function2();

	return(0);
}
