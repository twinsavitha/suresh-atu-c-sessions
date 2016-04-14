/*
 * Vectors.cpp
 *
 *  Created on: 20-Dec-2013
 */

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
    vector<int> intVec;

    cout << "Size of the vector is " << intVec.size() << endl;
    cout << "Capacity of the vector is " << intVec.capacity() << endl;

    intVec.push_back(3);  // inserts an element into vector
    intVec.push_back(7);
    cout << "Element at index 1 is " << intVec[1] << endl;
    cout << "Size of the vector is " << intVec.size() << endl;
    cout << "Capacity of the vector is " << intVec.capacity() << endl;

    intVec.push_back(9);
    cout << "Size of the vector is " << intVec.size() << endl;
    cout << "Capacity of the vector is " << intVec.capacity() << endl;

    intVec.push_back(7);
    cout << "Size of the vector is " << intVec.size() << endl;
    cout << "Capacity of the vector is " << intVec.capacity() << endl;

    intVec.push_back(23);
    intVec.push_back(17);
    intVec.push_back(4);
    cout << "Size of the vector is " << intVec.size() << endl;
    cout << "Capacity of the vector is " << intVec.capacity() << endl;

    intVec.push_back(43);
    intVec.push_back(72);
    intVec.push_back(65);


    cout << "Size of the vector is " << intVec.size() << endl;
    cout << "Capacity of the vector is " << intVec.capacity() << endl;

    intVec.pop_back();
    cout << "The size of the vector is " << intVec.size() << endl;

    intVec.reserve(32);  // Reserves the capacity to the specified number.
    cout << "Size of the vector is " << intVec.size() << endl;
    cout << "Capacity of the vector is " << intVec.capacity() << endl;

    return(0);
}

