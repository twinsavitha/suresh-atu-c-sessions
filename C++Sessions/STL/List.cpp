/*
 * List.cpp
 *
 *  Created on: 21-Dec-2013
 */

#include <iostream>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::list;

int main()
{
	list<int> listObj;
	listObj.push_back(23);
	listObj.push_front(13);
	listObj.push_back(33);
	listObj.push_back(43);

	list<int>::iterator iter = listObj.begin();

	while ( iter != listObj.end() )
	{
		cout << *iter << endl;
		++iter;
	}

	list<int>::reverse_iterator rIter = listObj.rbegin();
	list<int>::reverse_iterator rIterEnd = listObj.rend();

	cout << "Traversing the list in the reverse direction(style 1) : " << endl;
	while (rIter != rIterEnd)
	{
		cout << *rIter << endl;
		rIter++;
	}

	// Iterate through the list using reverse_iterator
	typedef list<int>::iterator iterList;
	iterList iterBegin(listObj.begin());

	iterList iterEnd(listObj.end());

	std::reverse_iterator<iterList> revIterBegin(iterEnd);
	std::reverse_iterator<iterList> revIterEnd(iterBegin);

	cout << "Traversing the list in the reverse direction(style 2) :" << endl;
	while (revIterBegin != revIterEnd)
	{
		cout << *revIterBegin << endl;
		revIterBegin++;
	}

	return(0);
}


