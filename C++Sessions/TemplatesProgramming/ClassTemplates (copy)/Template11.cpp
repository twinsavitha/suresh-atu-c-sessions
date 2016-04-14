// Demonstrates class template specialization

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <typename T>
class compare
{
public:
	compare(T val1, T val2)
		:value1_(val1),
		 value2_(val2)
	{}
	T maxValue()
	{
		return(value1_ > value2_ ? value1_ : value2_);
	}
private:
	T value1_;
	T value2_;
};


// Explicit specialization
template<>
string compare<string>::maxValue()
{
	return( value1_.compare(value2_) ? value1_ : value2_ );
}

int main()
{
	compare<int> compNumbers(5, 10);
	cout <<	compNumbers.maxValue() << endl;
	
	string s1("ABC"), s2("BBC");
	compare<string> compStrings(s1, s2);
	cout << compStrings.maxValue() << endl;
	return(0);
}
