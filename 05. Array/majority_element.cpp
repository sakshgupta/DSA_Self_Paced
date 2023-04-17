#include <iostream>
using namespace std;

void mine(int arr[], int n)
{
    int major = -1, c = 0;
    for (int i = 0; i < n; i++)
    {
        c = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] == arr[i])
                c++;
            if (c >= n / 2)
                major = i;
        }
    }
    cout << major << endl;
}

void efficient(int arr[], int n)
{
    int res = 0, c = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[res])
            c++;
        else
            c--;
        if (c == 0)
        {
            res = i;
            c = 1;
        }
    }
    c = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[res])
            c++;
    }
    if (c <= n / 2)
        res = -1;
    cout << res << endl;
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int arr[] = {20, 30, 40, 50, 50, 50, 50, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    // mine(arr, n);
    efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}