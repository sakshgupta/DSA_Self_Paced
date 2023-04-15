#include <iostream>
using namespace std;

bool mine(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0 && i % 2 != 0)
            return false;
    }
    return true;
}

bool naive(int n)
{
    if (n == 0)
        return false;
    while (n > 1)
    {
        if (n % 2 != 0)
            return false;
        n /= 2;
    }
    return true;
}

bool efficient(int n)
{
    // if (n == 0)
    //     return false;
    // return ((n & (n - 1)) == 0);
    return (n != 0) && ((n & (n - 1)) == 0);
}

int main()
{
    cout << naive(16) << endl;
    cout << mine(16) << endl;
    cout << efficient(16) << endl;
    return 0;
}