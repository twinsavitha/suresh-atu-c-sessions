/*
 * Sets.cpp
 *
 *  Created on: 26-Dec-2013
 */

#include <iostream>
#include <set>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::set;
using std::string;

int main()
{
	set<int> pollObj;
	char chChoice = 'y';

	while (chChoice == 'y' || chChoice == 'Y')
	{
		int nRollNo;
		cout << "Please enter your roll number if interested to join the event" << endl;
		cin >> nRollNo;
		pollObj.insert(nRollNo);
		cout << "Do you want to add few more (yes/no)" << endl;
		cin >> chChoice;
	}

	cout << "Total enrollments for the event is " << pollObj.size() << endl;

	set<int>::iterator iter = pollObj.begin();
	set<int>::iterator iterEnd = pollObj.end();
	cout << "Enrollments are\n";
	while (iter != iterEnd)
	{
		cout << *iter << endl;
		iter++;
	}
	return(0);
}


