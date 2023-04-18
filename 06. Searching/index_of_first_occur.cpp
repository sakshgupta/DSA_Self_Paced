#include <iostream>
using namespace std;

void mine(int arr[], int n, int x)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int m = (s + e) / 2;
        if (arr[m] > x)
            e = m - 1;
        else if (arr[m] < x)
            s = m + 1;
        else
        {
            if (m == 0 or arr[m] != arr[m - 1])
                cout << m << endl;
            else
                e = m - 1;
        }
    }
    cout << -1 << endl;
}

void efficient(int arr[], int n)
{
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int n = sizeof(arr) / sizeof(arr[0]);
    mine(arr, n, 20);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}