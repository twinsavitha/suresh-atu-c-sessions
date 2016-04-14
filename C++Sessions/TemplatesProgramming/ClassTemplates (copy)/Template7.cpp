// Demonstrating the instantiation of the 
// member functions of the class template 
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class CArrayT
{
public:
	CArrayT(int size)
	{
		size_ = size;
		pArray_ = new T[sizeof(T)*size_];
	}

	~CArrayT() { delete []pArray_; }
	int getSize() {	return(size_); }
	void setValue(T tVal)
	{
		for (int nIdx = 0; nIdx < size_; nIdx++) pArray_[nIdx] = tVal;
	}
	void showValues()
	{
		for (int nIdx = 0; nIdx < size_; nIdx++) {cout << pArray_[nIdx] << endl;}
	}

private:
	int size_;
	T *pArray_;
};


int main()
{
	// Instantiates the class with int
	CArrayT<int> iArrObj(5);
	// Instantiates the member function setValue()
	// in the class instantiated with int;
	iArrObj.setValue(23);
	iArrObj.showValues();
	// Instantiates the member function getSize()
	// in the class instantiated with int;
	cout <<	"Size of integer array is " << iArrObj.getSize() << endl;


	// Instantiates the class with char
	CArrayT<char> chArrObj(7);
	// Instantiates the member function setValue()
	// in the class instantiated with char;
	chArrObj.setValue('z');
	chArrObj.showValues();
	// Instantiates the member function getSize()
	// in the class instantiated with char;
	cout << "Size of character array is " << chArrObj.getSize() << endl;

	return(0);
}
