/*
 * Queues.cpp
 *
 *  Created on: 24-Dec-2013
 */

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> qObj;
	if (qObj.empty())
	{
		cout << "The Q is empty.\n";
	}

	qObj.push(23);
	qObj.push(3);
	qObj.push(-7);
	cout << "Size of the queue is " << qObj.size() << "\n";
	cout << "Element in the front of the Q is " << qObj.front() << "\n";
	cout << "Last element in the Q is " << qObj.back() << "\n";
	qObj.pop();
	cout << "Size of the queue is " << qObj.size() << "\n";
	return(0);
}





