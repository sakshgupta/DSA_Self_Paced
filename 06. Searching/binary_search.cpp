#include <iostream>
using namespace std;

void mine(int arr[], int n, int x)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int m = (s + e) / 2;
        if (arr[m] == x)
        {
            cout << m << endl;
            break;
        }
        if (x > arr[m])
            s = m + 1;
        else
            e = m - 1;
    }
    cout << -1 << endl;
}

void efficient(int arr[], int n)
{
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int arr[] = {15, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    mine(arr, n, 7);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}