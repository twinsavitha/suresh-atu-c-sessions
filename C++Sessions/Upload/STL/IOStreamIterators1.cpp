/*
 * IOStreamIterators1.cpp
 *
 *  Created on: 02-Jan-2014
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <iterator>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;
using std::istream_iterator;
using std::ostream_iterator;

int main()
{
    string file_name;
    cout << "Please enter the name of file to open: ";
    cin >> file_name;

    if ( file_name.empty() || !cin )
    {
         cerr << "\nUnable to read file name\n";
         return -1;
    }

    ifstream infile( file_name.c_str());
    if ( ! infile )
    {
         cerr << "\nUnable to open file " << file_name << endl;
         return -2;
    }

    istream_iterator<string> ins( infile ), eos;
    ostream_iterator<string> outs( cout, " " );
    cout << file_name << endl;
    cout << "------------------------" << endl;
    std::copy( ins, eos, outs );
    return(0);
}




