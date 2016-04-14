// regex_replace.cpp

// Demonstrates the usage of regular expressions
// for searching and replacing a pattern
#include <boost/regex.hpp>
#include <iostream>
#include <string>

using boost::regex;
using std::string;
using std::cout;
using std::cin;

int main()
{
	string strStmt = "TCS is a part of the TATA group";
	string strRegExp("TCS");
    regex pattern(strRegExp, boost::regex::basic|boost::regex::icase);

	strStmt = boost::regex_replace(strStmt, pattern, "Tata Consultancy Services");
	cout << strStmt;

	return(0);
}
