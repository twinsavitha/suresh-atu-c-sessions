/*
 * Algorithms.cpp
 *
 *  Created on: 27-Dec-2013
 */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;
using std::find;

void searchArray();
void searchVector();
void searchList();
void sortAscending();
void sortDescending();

int nNumbers[] = { 10, 40, 60, 30, 20, 50 };
int main()
{
	searchArray();
	searchVector();
	searchList();
	sortAscending();
	sortDescending();
	return(0);
}

void searchArray()
{
	int nValue;
	cout << "Enter the number to be searched in the array\n";
	cin >> nValue;
	int *pSearch = find(&nNumbers[0], &nNumbers[6], nValue);

	cout << "Number "
		 << (pSearch == &nNumbers[6] ? "not found" : "found")
		 << endl;
}

void searchVector()
{
	vector<int> intVec(nNumbers, nNumbers+6);
	int nValue;
	cout << "Enter the number to be searched in the vector\n";
	cin >> nValue;
	vector<int>::iterator iter = find(intVec.begin(), intVec.end(), nValue);
	cout << "Number "
		 << (iter == intVec.end() ? "not found" : "found")
		 << endl;
}

void searchList()
{
	list<int> intList(nNumbers, nNumbers+6);
	int nValue;
	cout << "Enter the number to be searched in the list\n";
	cin >> nValue;
	list<int>::iterator iter = find(intList.begin(), intList.end(), nValue);
	cout << "Number "
		 << (iter == intList.end() ? "not found" : "found")
		 << endl;
}

void sortAscending()
{
	cout << "\nThe values in the ascending order are\n";
	vector<int> tempVec(nNumbers, nNumbers+6);
	vector<int>::iterator iter = tempVec.begin();
	vector<int>::iterator iterEnd = tempVec.end();
	sort(tempVec.begin(), tempVec.end());
	while (iter != iterEnd)
	{
		cout << *iter << "\t";
		iter++;
	}
}

void sortDescending()
{
	cout << "\nThe values in the descending order are\n";
	vector<int> tempVec(nNumbers, nNumbers+6);
	vector<int>::iterator iter = tempVec.begin();
	vector<int>::iterator iterEnd = tempVec.end();

	// Either form can be used to sort the elements
	sort(iter, iterEnd, std::greater<int>());
	//sort(tempVec.rbegin(), tempVec.rend());
	while (iter != iterEnd)
	{
		cout << *iter << "\t";
		iter++;
	}
}
