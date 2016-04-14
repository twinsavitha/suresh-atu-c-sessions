/*
 * Maps.cpp
 *
 *  Created on: 26-Dec-2013
 */

#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::string;

typedef string EmpId;
typedef string EmpName;
typedef map<EmpId, EmpName> EmpRecords;
typedef map<EmpId, EmpName>::value_type empRecType;

int main()
{
	EmpRecords empRecObj;
	char chUserChoice = 'y';
	EmpId tempID;
	EmpName tempName;

	while (chUserChoice == 'y' || chUserChoice == 'Y')
	{
		cout << "Enter the employee number" << endl;
		cin >> tempID;
		cout << "Enter the name of the employee" << endl;
		cin >> tempName;

		// Way to insert elements through key as the index
		// using the operator[]
		empRecObj[tempID] = tempName;
		cout << "Do you want add more records (yes/no)?" << endl;
		cin >> chUserChoice;
	}

	// another way of inserting elements into the map
	//empRecObj.insert(empRecType("103", "Delhi"));

	EmpRecords::iterator iter = empRecObj.begin();
	EmpRecords::iterator iterEnd = empRecObj.end();
	while (iter != iterEnd)
	{
		cout << iter->first << '\t' << iter->second << endl;
		++iter;
	}

	cout << "Enter the ID number of the employee to search" << endl;
	cin >> tempID;
	iter = empRecObj.find(tempID);
	if (iter != iterEnd)
	{
		cout << "Record found\n" << iter->first << '\t' << iter->second << endl;
	}
	else
	{
		cout << "No record found for " << tempID << endl;
	}

	// insert does no changes if the key is present in the map
	// empRecObj.insert(empRecType("103", "Mumbai"));
	// operator[] changes the value if the key is present
	//			  adds the key/value pair if the key is not present
	empRecObj["103"] = "Mumbai";

	iter = empRecObj.begin();
	while (iter != iterEnd)
	{
		cout << iter->first << '\t' << iter->second << endl;
		++iter;
	}
	return(0);
}

