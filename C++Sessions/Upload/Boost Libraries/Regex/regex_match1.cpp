// regex_match.cpp

// Demonstrates the usage of regular expressions for matching a pattern
#include <boost/regex.hpp>
#include <iostream>
#include <string>

using boost::regex;
using std::string;
using std::cout;
using std::cin;

int main()
{
	string line("Tomato is the king of fruits");
	string sRegExp("^M.*");
    regex pattern( sRegExp, boost::regex::basic );

	boost::smatch matches;
	bool bMatchResult = regex_match(line, matches, pattern);
	if (bMatchResult)
	{
		cout << "Match successful: " << matches << '\n';
	}
	else
	{
		cout << "Match failed\n";
	}
	return(0);
}
