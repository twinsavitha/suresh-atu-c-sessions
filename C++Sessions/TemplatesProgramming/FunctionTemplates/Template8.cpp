#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

// Generic template definition
// This definition is not right for the strings
template <typename T>
T max(T t1, T t2)
{
	return(t1>t2 ? t1 : t2);
}

// Template Explicit Specialization
// This specialized function is called whenever the
// template parameter is of type pointer to const char.
// For all others the template function would be instantiated.
typedef const char * PCC;
template<> PCC max<PCC>(PCC t1, PCC t2)
{
	return(strcmp(t1, t2)>0 ? t1 : t2);
}


int main()
{
	// call instantiated as
	// int max<int>(int, int);
	int nMaxVal = max(5, 10);
	cout << "Max value is " << nMaxVal << endl;

	// calls explicit specialization
	// const char * max<const char *>(const char *, const char *);
	const char *strMax = max("Templates", "confusing");
	cout << "Max str is " << strMax << endl;

	return(0);
}
