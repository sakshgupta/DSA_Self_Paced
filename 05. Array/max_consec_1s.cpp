#include <iostream>
using namespace std;

void mine(int arr[], int n)
{
    int maxs = arr[0], s = 0;
    for (int i = 0; i < n; i++)
    {
        s = 0;
        for (int j = i; j < n; j++)
        {
            s += arr[j];
            maxs = max(maxs, s);
        }
    }
    cout << maxs << endl;
}

void efficient(int arr[], int n)
{
    int res = arr[0], maxending = arr[0];
    for (int i = 0; i < n; i++)
    {
        maxending = max(maxending + arr[i], arr[i]);
        res = max(res, maxending);
    }
    cout << res << endl;
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int arr[] = {-3, 8, -2, 4, -5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    // mine(arr, n);
    efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}