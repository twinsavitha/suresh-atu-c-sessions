#include <iostream>

using namespace std;

int divide(int num, int den)
{
    return(num/den);
} 

int main()
{
    int x = 10, y = 2;
    cout << divide(x, y);
    y = 0;
    cout << divide(x, y);
    return(0);
}
