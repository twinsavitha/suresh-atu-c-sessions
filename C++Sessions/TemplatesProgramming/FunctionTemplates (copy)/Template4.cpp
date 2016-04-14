#include <iostream>
using std::cout;
using std::endl;

// Template Argument Deduction

// Template instantiated to min(int *, int);
template <class T>
// the first parameter is a T*
T min( T array[], int size)
{
   T min_val = array[0];
   for ( int i = 1; i < size; ++i )
      if ( array[i] < min_val )
         min_val = array[i];
   
   return min_val;
}

// Template instantiated to minC(const int *, int);
template <typename T>
T minC(const T array[], int size)
{
   T min_val = array[0];
   for ( int i = 1; i < size; ++i )
      if ( array[i] < min_val )
         min_val = array[i];
   
   return min_val;
}

int intArray[4] = {43, 23, 33, 13};

int main()
{
	int nArraySize = sizeof(intArray)/sizeof(intArray[0]);
	
	cout << min(intArray, nArraySize);  //calls min(int *, int)
	cout << endl;

	// adds the qualifier const to the int *
	cout << minC(intArray, nArraySize); //calls minC(const int *, int)
}
