#include <iostream>
using namespace std;

void mine(int arr[], int n)
{
    int c1 = 0, c0 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1 && arr[i + 1] == 0)
            c1++;
        else if (arr[i] == 0 && arr[i + 1] == 1)
            c0++;
    }
    if (arr[n - 1] == 1)
        c1++;
    else
        c0++;

    if (c1 > c0)
    {
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0 && arr[i + 1] != 0)
            {
                index = i;
                continue;
            }
            else if (arr[i] == 1 && arr[i - 1] == 0)
            {
                cout << "From " << index << " to " << i - 1 << endl;
            }
        }
    }
    else
    {
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1 && arr[i + 1] != 1)
            {
                index = i;
                continue;
            }
            else if (arr[i] == 0 && arr[i - 1] == 1)
            {
                cout << "From " << index << " to " << i - 1 << endl;
            }
        }
    }
}

void efficient(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            if (arr[i] != arr[0])
                cout << "From " << i << " to ";
            else
                cout << (i - 1) << endl;
        }
    }
    if (arr[n - 1] != arr[0])
        cout << (n - 1) << endl;
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int arr[] = {0, 0, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    // mine(arr, n);
    efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}