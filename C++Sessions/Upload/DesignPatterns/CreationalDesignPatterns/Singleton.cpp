// Singleton.cpp

#include <iostream>
using std::cout;
using std::endl;

class GlobalClass
{
public:
	static GlobalClass *getInstance()
	{
		if (!pGlobalClassObj_)
		{
			pGlobalClassObj_ = new GlobalClass;
		}
		return pGlobalClassObj_;
	}

	int getValue() { return(value_); }
	void setValue(int val) { value_ = val; }
private:
	int value_;
	static GlobalClass *pGlobalClassObj_;

	GlobalClass(int val = 0) : value_(val) {}
};

// Allocate and initialize the static data member.
GlobalClass *GlobalClass::pGlobalClassObj_ = 0;

void function1()
{
	GlobalClass::getInstance()->setValue(10);
	cout << "function1(): Value is " << GlobalClass::getInstance()->getValue() << '\n';
}

void function2()
{
	GlobalClass::getInstance()->setValue(20);
	cout << "function2(): Value is " << GlobalClass::getInstance()->getValue() << '\n';
}

int main()
{
	cout << "main(): Value is " << GlobalClass::getInstance()->getValue() << '\n';
	function1();
	function2();
}
