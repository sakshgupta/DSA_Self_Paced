#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

void mine(int arr[], int n)
{
    int res = INT_MAX;
    sort(arr, arr + n);
    for (int i = 1; i < n; i++)
    {
        res = min(res, arr[i] - arr[i - 1]);
    }
    cout << res << endl;
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int a[] = {1, 8, 12, 5, 18};
    int n = sizeof(a) / sizeof(a[0]);
    mine(a, n);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << " ";
    }
}