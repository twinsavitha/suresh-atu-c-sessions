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
	void showValues()
	{
		for (int nIdx = 0; nIdx < size_; nIdx++) {cout << pArray_[nIdx] << endl;}
	}

private:
	// cannot have the members named as same as the template parameter list
	// typedef int T;
	// T size_;
	int size_;
	T *pArray_;
};

int main()
{
	CArrayT<int> iArrObj(5);
	iArrObj.showValues();
	cout <<	"Size of integer array is " << iArrObj.getSize() << endl;

	CArrayT<double> dArrObj(10);
	dArrObj.showValues();
	cout << "Size of double array is " << dArrObj.getSize() << endl;

	CArrayT<char> cArrObj(5);
	cArrObj.showValues();
	cout << "Size of char array1 is " << cArrObj.getSize() << endl;
	
	CArrayT<char> *pCArrObj = new CArrayT<char>(10);
	pCArrObj->showValues();
	cout << "Size of char array2 is " <<  pCArrObj->getSize() << endl;

	return(0);
}
