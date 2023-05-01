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

void qSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h);
        qSort(arr, l, p - 1);
        qSort(arr, p + 1, h);
    }
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int a[] = {8, 4, 7, 9, 3, 10, 5};
    int n = sizeof(a) / sizeof(a[0]);
    qSort(a, 0, n - 1);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << " ";
    }
}