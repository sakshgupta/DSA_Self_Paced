#include <bits/stdc++.h>
using namespace std;

// Effecient
int mine(int arr[], int n, int x)
{
    int l = 0, h = n - 1;
    while (l <= h)
    {
        int m = (l + h) / 2;
        if (arr[m] == x)
            return m;
        else if (arr[m + 1] == x)
            return m + 1;
        else if (arr[m - 1] == x)
            return m - 1;
        else if (arr[m] > x)
            h = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {3, 2, 40, 4, 60, 50, 70, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << mine(arr, n, 3);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}