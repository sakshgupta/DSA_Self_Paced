#include <iostream>
using namespace std;

int power(int x, int n)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1) // n%2!=0
            res = res * x;
        x = x * x;
        n = n >> 1; // n=n/2
    }
    return res;
}

int main()
{
    int x = 4, n = 5;
    cout << power(x, n);
    return 0;
}