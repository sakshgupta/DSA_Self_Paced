#include <iostream>
using namespace std;

void mine(int arr[], int n)
{
    int x = 1;
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int m = (s + e) / 2;
        if (arr[m] == x and arr[m] != arr[m - 1])
        {
            cout << n - m << endl;
            break;
        }
        if (x > arr[m])
            s = m + 1;
        else
            e = m - 1;
    }
    cout << -1 << endl;
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int arr[] = {0, 0, 1, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    mine(arr, n);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}