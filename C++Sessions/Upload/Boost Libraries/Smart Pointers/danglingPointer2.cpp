// danglingPointer2.cpp

// Demonstrates the concept of dangling pointers
// Compile as g++ -Wall -g danglingPointer.cpp and run the a.out
#include <iostream>
using std::cout;

class Test
{
public:
	Test(int i)
	{
		pValue_ = new int(i);
		cout << "Constructor: " << &pValue_ << ' ' << pValue_ << '\n';
	}
	~Test()
	{
		cout << "Destructor: " << &pValue_ << ' ' << pValue_ << '\n'; 
		delete pValue_;
	}
	void printVal() { cout << "The value is " << *pValue_ << "\n"; }
private:
	int *pValue_;
};

void someFunc(Test x)
{
	cout << "In someFunc" << "\n";
}

int main()
{
	Test testObj(17);

	someFunc(testObj);  // testObj passed-by-value; the temporary object is created with a shallow copy
	testObj.printVal();

	return(0);
}
