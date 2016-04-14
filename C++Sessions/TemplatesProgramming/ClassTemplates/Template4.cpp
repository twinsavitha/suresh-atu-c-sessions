// Demonstrating the shorthand notation and full template parameter listing
#include <iostream>
using std::cout;
using std::endl;

// Demonstrating default values to the parameters
// size here is a nontype template parameter
template<typename T = int, int size = 7>
class CArrayT
{
public:
	CArrayT() // Need not specify the template parameter
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

template<typename T>
void display(CArrayT<T> &rArrObj) // Must specify the full template parameter listing
{
	CArrayT<T> *pArrObj = &rArrObj; // Must specify the full template parameter listing
	cout << "Size of the referenced array object is " << rArrObj.getSize() << endl;
	cout << "Size of the referenced array object is " << pArrObj->getSize() << endl;
}

int main()
{
	// Uses the default value 7 for the size
	CArrayT<int> iArrObj;
	iArrObj.showValues();
	cout <<	"Size of integer array is " << iArrObj.getSize() << endl;
	
	display(iArrObj);

	return(0);
}
