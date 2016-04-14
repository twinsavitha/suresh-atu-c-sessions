// Demonstrating the class template instantiation
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

/*
class CArrayT
{
	.....
	.....
private:
	int size_;
	int *pArray_;
};


class CArrayT
{
	.....
	.....
private:
	int size_;
	char *pArray_;
};
*/

int main()
{
	// Instantiates the class with int
	CArrayT<int> iArrObj(5);
	iArrObj.setValue(23);
	iArrObj.showValues();
	cout <<	"Size of integer array is " << iArrObj.getSize() << endl;
	
	// Instantiates the class with char
	CArrayT<char> chArrObj(7);
	chArrObj.setValue('z');
	chArrObj.showValues();
	cout << "Size of character array is " << chArrObj.getSize() << endl;

	return(0);
}
