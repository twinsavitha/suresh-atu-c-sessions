/*
 * Stacks.cpp
 *
 *  Created on: 24-Dec-2013
 */

#include <iostream>
#include <stack>

int main()
{
	std::stack<int> stObj;

	stObj.push(23);
	stObj.push(-7);
	stObj.push(0);
	std::cout << "The element at top is " << stObj.top() << "\n";
	std::cout << "Number of elements in the stack is " << stObj.size() << "\n";
	stObj.push(14);
	stObj.push(19);

	while (stObj.empty() == false)
	{
		std::cout << "Element retrieved from top is " << stObj.top() << "\n";
		stObj.pop();
	}
	return(0);
}






