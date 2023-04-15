#include <iostream>
using namespace std;

void leftshift(int n, int k)
{
    if (n & (1 << (k)) != 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

void rightshift(int n, int k)
{
    if ((n >> (k)) & 1 == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    leftshift(4, 2);
    rightshift(4, 2);
    return 0;
}