/*
 * PriorityQueue.cpp
 *
 *  Created on: 24-Dec-2013
 */

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;

int main()
{
	int nArray[] = { 20, 10, 50, 40, 60 };
	typedef priority_queue<int> pqInt;
	pqInt pqObj(nArray, nArray+5);
	pqObj.push(30);

	for (int nCnt = 1; nCnt <= 6; nCnt++)
	{
		cout << pqObj.top() << endl;
		pqObj.pop();
	}


	// parameter 2: container object - here a vector
	// parameter 3: comparison object to place the elements in an order
	priority_queue< int, vector<int>, std::greater<int> > lessIsHigh(nArray, nArray+5);
	cout << "\nPriority Queue with less value having higher priority\n";
	lessIsHigh.push(40);
	for (int nCnt = 1; nCnt <= 6; nCnt++)
	{
		cout << lessIsHigh.top() << endl;
		lessIsHigh.pop();
	}

	return(0);
}


