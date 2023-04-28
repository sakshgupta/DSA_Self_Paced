#include <iostream>
using namespace std;

int merge(int a[], int low, int mid, int high)
{
    int n1 = mid - low + 1, n2 = high - mid;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
    {
        left[i] = a[low + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = a[mid + 1 + i];
    }

    int i = 0, j = 0, k = low, res = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
            res = res + (n1 - i);
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = left[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        a[k] = right[j];
        k++;
        j++;
    }
    return res;
}

int mergeSort(int a[], int l, int r)
{
    cout << r << " " << l << endl;
    int res = 0;
    if (r > l)
    {
        int m = l + (r - l) / 2;
        res += mergeSort(a, l, m);
        res += mergeSort(a, m + 1, r);
        res += merge(a, l, m, r);
    }
    return res;
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int a[] = {2, 4, 1, 3, 5};
    int n = sizeof(a) / sizeof(a[0]);
    cout << mergeSort(a, 0, n - 1);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << " ";
    }
}