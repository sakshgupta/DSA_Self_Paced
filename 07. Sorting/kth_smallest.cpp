#include <iostream>
using namespace std;

int partition(int arr[], int l, int h)
{
    int p = arr[h];
    int i = l - 1;
    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] < p)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}

// also called QUICK SELECT algorithm
int mine(int arr[], int n, int k)
{
    int l = 0, h = n - 1;
    while (l <= h)
    {
        int p = partition(arr, l, h);
        if (p == k - 1)
            return arr[p];
        else if (p > k - 1)
            h = p - 1;
        else
            l = p + 1;
    }
    return -1;
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int a[] = {7, 10, 4, 20, 15};
    int n = sizeof(a) / sizeof(a[0]);
    cout << mine(a, n, 4);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << " ";
    }
}