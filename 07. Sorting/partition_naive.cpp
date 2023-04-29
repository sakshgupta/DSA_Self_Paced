#include <iostream>
using namespace std;

void mine(int arr[], int l, int h, int p)
{
    int temp[h - l + 1], index = 0;
    for (int i = 0; i <= h; i++)
    {
        if (arr[i] <= arr[p])
        {
            temp[index] = arr[i];
            index++;
        }
    }

    for (int i = 0; i <= h; i++)
    {
        if (arr[i] > arr[p])
        {
            temp[index] = arr[i];
            index++;
        }
    }
    for (int i = l; i <= h; i++)
    {
        arr[i] = temp[i - l];
    }
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int a[] = {5, 13, 6, 9, 12, 11, 8};
    int n = sizeof(a) / sizeof(a[0]);
    mine(a, 0, n - 1, 6);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << " ";
    }
}