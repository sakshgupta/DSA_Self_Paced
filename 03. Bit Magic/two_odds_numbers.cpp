#include <iostream>
using namespace std;

// checks if the last set bit is set or not
bool last_bit_set(int x)
{
    return (x & 1 != 0);
}

void mine(int a[], int n)
{
    int temp = 0, x1 = 0, x2 = 0;
    // calculates xor of all the elements of the array
    for (int i = 0; i < n; i++)
    {
        temp = temp ^ a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int sn = temp & ~(temp - 1);
        // if the number is even
        if ((a[i] & sn) == 0)
            x2 = x2 ^ a[i];
        else
            x1 = x1 ^ a[i];
    }
    cout << x1 << " " << x2 << endl;
}

void efficient(int a[], int n)
{
    int XOR = 0, res1 = 0, res2 = 0;
    for (int i = 0; i < n; i++)
    {
        XOR = XOR ^ a[i];
    }
    int sn = XOR & ~(XOR - 1); // Gives the rightmost bit
    for (int i = 0; i < n; i++)
    {
        if ((a[i] & sn) != 0)
            res1 = res1 ^ a[i];
        else
            res2 = res2 ^ a[i];
    }
    cout << res1 << " " << res2 << endl;
}

int main()
{
    int a[] = {3, 4, 3, 4, 2, 4, 4, 6, 7, 7};
    // int a[] = {20, 15, 20, 13, 15, 15, 13, 13};
    int n = sizeof(a) / sizeof(a[0]);
    mine(a, n);
    efficient(a, n);
    return 0;
}