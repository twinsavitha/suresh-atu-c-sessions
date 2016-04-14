/*
 * Deques.cpp
 *
 *  Created on: 21-Dec-2013
 */

#include <iostream>
#include <deque>

using std::cout;
using std::cin;
using std::endl;
using std::deque;

int main()
{
    deque<int> deqObj;
    deqObj.push_back(43);
    deqObj.push_front(23);
    deqObj.push_back(63);

    for (unsigned int nIdx = 0; nIdx < deqObj.size(); ++nIdx)
    {
    	cout << deqObj[nIdx] << endl;
    }

    cout << "\nPopping out an element" << endl;
    deqObj.pop_back();
    for (unsigned int nIdx = 0; nIdx < deqObj.size(); ++nIdx)
    {
    	cout << deqObj[nIdx] << endl;
    }

    cout << "\nPopping out an element" << endl;
    deqObj.pop_front();
    for (unsigned int nIdx = 0; nIdx < deqObj.size(); ++nIdx)
    {
    	cout << deqObj[nIdx] << endl;
    }
    return(0);
}



