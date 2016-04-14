// regex_search.cpp

// Demonstrates the usage of regular expressions for searching a pattern
#include <boost/regex.hpp>
#include <iostream>
#include <string>

using boost::regex;
using std::string;
using std::cout;
using std::cin;

int main()
{
    string strLine;
	//string strRegExp("@@*"); 
	string strRegExp("[0-9]$"); 
    regex pattern(strRegExp, boost::regex::basic);

    while (cin)
    {
		std::getline(cin, strLine);
		boost::smatch matches;
        if (boost::regex_search(strLine, matches, pattern))
		{
			cout << strLine << '\n';
		}
    }
	return(0);
}
