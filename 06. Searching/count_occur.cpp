#include <iostream>
using namespace std;

int firstocc(int arr[], int n, int x)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int m = (s + e) / 2;
        if (arr[m] == x and arr[m] != arr[m - 1])
        {
            return m;
        }
        if (x > arr[m])
            s = m + 1;
        else
            e = m - 1;
    }
    return -1;
}

int lastocc(int arr[], int n, int x)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int m = (s + e) / 2;
        if (arr[m] == x and arr[m] != arr[m + 1])
        {
            return m;
        }
        if (x >= arr[m])
            s = m + 1;
        else
            e = m - 1;
    }
    return -1;
}

void mine(int arr[], int n, int x)
{
    int first = firstocc(arr, n, x);
    if (first == -1)
        return;
    cout << (lastocc(arr, n, x) - first + 1);
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int arr[] = {1, 1, 10, 20, 20, 20, 20, 40, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    mine(arr, n, 4);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}