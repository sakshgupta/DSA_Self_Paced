#include <iostream>
using namespace std;

int mine(int arr[], int n, int x, int s, int e)
{
    int m = (s + e) / 2;
    if (s > e)
        return -1;
    if (arr[m] == x)
    {
        return m;
    }
    if (x > arr[m])
    {
        s = m + 1;
        mine(arr, n, x, s, e);
    }
    else
    {
        e = m - 1;
        mine(arr, n, x, s, e);
    }
}

void efficient(int arr[], int n)
{
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << mine(arr, n, 60, 0, n - 1) << endl;
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}