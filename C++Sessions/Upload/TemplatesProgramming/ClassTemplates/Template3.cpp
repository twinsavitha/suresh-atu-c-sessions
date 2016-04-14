#include <iostream>
using std::cout;
using std::endl;

// Demonstrating default values to the parameters
// size here is a nontype template parameter
template<typename T = int, int size = 7>
class CArrayT
{
public:
	CArrayT()
	{
		size_ = size;
		pArray_ = new T[sizeof(T)*size_];
	}

	~CArrayT() { delete []pArray_; }
	int getSize() {	return(size_); }
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
	// Uses the default value 7 for the size
	CArrayT<int> iArrObj;
	iArrObj.showValues();
	cout <<	"Size of integer array is " << iArrObj.getSize() << endl;

	CArrayT<double, 10> dArrObj;
	dArrObj.showValues();
	cout << "Size of double array is " << dArrObj.getSize() << endl;

	CArrayT<char, 5> cArrObj;
	cArrObj.showValues();
	cout << "Size of char array1 is " << cArrObj.getSize() << endl;
	
	// Uses the default value 7 for the size
	CArrayT<char> *pCArrObj = new CArrayT<char>;
	pCArrObj->showValues();
	cout << "Size of char array2 is " <<  pCArrObj->getSize() << endl;
	
	// T = int; size = 7
	CArrayT<> defArrObj;
	defArrObj.showValues();
	cout << "Size of the defArrObj is " << defArrObj.getSize() << endl;

	return(0);
}
