#include <iostream>
using namespace std;

int bsearch(int arr[], int x, int s, int e)
{
    while (s <= e)
    {
        int m = (s + e) / 2;
        if (arr[m] == x)
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

int mine(int arr[], int x)
{
    if (arr[0] == x)
        return 0;
    int i = 1;
    while (arr[i] < x)
    {
        i *= 2;
    }
    if (arr[i] == x)
        return i;
    return bsearch(arr, x, i / 2 + 1, i - 1);
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int arr[] = {1, 10, 15, 20, 40, 60, 80, 90, 100, 200, 500, 1000};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << mine(arr, 100);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}