/*
 * Iterators.cpp
 *
 *  Created on: 30-Dec-2013
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

typedef vector<int>::iterator fwdIter;
typedef vector<int>::const_iterator constIter;
typedef vector<int>::reverse_iterator revIter;
typedef vector<int>::const_reverse_iterator constRevIter;

int main()
{
	int nArray[] = {10, 90, 30, 20, 70};
	vector<int> intVec(nArray, nArray+5);

	cout << "Iterating with forward iterator" << endl;
	fwdIter fIter = intVec.begin();
	fwdIter fIterEnd = intVec.end();
	while (fIter != fIterEnd)
	{
		cout << *fIter << endl;
		++fIter;
	}

	cout << "Iterating forward with const iterator" << endl;
	const vector<int> constIntVec(intVec);
	constIter cIter = constIntVec.begin();
	constIter cIterEnd = constIntVec.end();
	while (cIter != cIterEnd)
	{
		cout << *cIter << endl;
		cIter++;
	}

	cout << "Iterating with reverse iterator" << endl;
	revIter rIter = intVec.rbegin();
	revIter rIterEnd = intVec.rend();
	while (rIter != rIterEnd)
	{
		cout << *rIter << endl;
		rIter++;
	}

	cout << "Iterating with reverse const iterator" << endl;
	constRevIter cRevIter = constIntVec.rbegin();
	constRevIter cRevIterEnd = constIntVec.rend();
	while (cRevIter != cRevIterEnd)
	{
		cout << *cRevIter << endl;
		cRevIter++;
	}

	// Insert iterators
	int nRepeatNos[] = {1,
			   	   	    2, 2,
			   	   	    3, 3, 3,
			   	   	    4, 4, 4, 4,
			   	   	    5, 5, 5, 5, 5};
	vector<int> ivec(nRepeatNos, nRepeatNos+15), uniqVec;
	unique_copy(ivec.begin(), ivec.end(), back_inserter(uniqVec));
	fwdIter iterNos = uniqVec.begin();
	fwdIter iterNosEnd = uniqVec.end();
	cout << "The unique values are\n";
	while (iterNos != iterNosEnd)
	{
		cout << *iterNos << endl;
		iterNos++;
	}

	return(0);
}
