#include <iostream>
#include <algorithm>
using namespace std;

int mine(int arr[], int n, int m)
{
    if (m > n)
        return -1;
    sort(arr, arr + n);
    int res = arr[m - 1] - arr[0];
    for (int i = 0; (i + m - 1) < n; i++)
    {
        res = min(res, (arr[i + m - 1] - arr[i]));
    }
    return res;
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int a[] = {7, 3, 2, 4, 9, 12, 56};
    int n = sizeof(a) / sizeof(a[0]);
    cout << mine(a, n, 3);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << " ";
    }
}