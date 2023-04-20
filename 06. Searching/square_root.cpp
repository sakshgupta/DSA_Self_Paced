#include <iostream>
using namespace std;

void mine(int x)
{
    int s = 1, e = x, ans = -1;
    while (s <= e)
    {
        int m = (s + e) / 2;
        if (m * m == x)
        {
            cout << m << endl;
            return;
        }
        if (x > m * m)
        {
            s = m + 1;
            ans = m;
        }
        else
            e = m - 1;
    }
    cout << ans << endl;
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int arr[] = {15, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    mine(14);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}