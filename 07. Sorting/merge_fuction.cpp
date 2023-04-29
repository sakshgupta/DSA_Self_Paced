#include <iostream>
using namespace std;

void mine(int a[], int n, int low, int mid, int high)
{
    int temp[n];
    int i = low, j = mid + 1, k = 0;
    while (i <= (mid - low) && j <= (high))
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= (mid - low))
    {
        temp[k] = a[i];
        k++;
        i++;
    }
    while (j <= (high))
    {
        temp[k] = a[j];
        k++;
        j++;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }
}

void merge(int a[], int low, int mid, int high)
{
    int n1 = mid - low + 1, n2 = high - mid;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
    {
        left[i] = a[low + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = a[n1 + i];
    }

    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            k++;
            i++;
        }
        else
        {
            a[k] = right[j];
            k++;
            j++;
        }
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
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int a[] = {5, 10, 30, 7, 15};
    int n = sizeof(a) / sizeof(a[0]);
    merge(a, 0, 2, 4);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << " ";
    }
}