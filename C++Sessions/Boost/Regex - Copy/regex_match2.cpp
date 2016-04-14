// regex.cpp

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
	//string strRegExp("@.*"); // include the search pattern between the quotes
	string strRegExp("@@*"); // include the search pattern between the quotes
    regex pattern(strRegExp, boost::regex::basic);

    while (cin)
    {
		std::getline(cin, strLine);
		boost::smatch matches;
        if (boost::regex_search(strLine, matches, pattern))
		{
			cout << matches << std::endl;
			cout << strLine << '\n';
		}
    }
	return(0);
}
