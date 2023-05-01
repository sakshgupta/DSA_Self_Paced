#include <iostream>
using namespace std;

int partition(int arr[], int l, int h)
{
    int p = arr[l];
    int i = l - 1, j = h + 1;
    while (true)
    {
        // Find leftmost larger element than pivot
        do
        {
            i++;
        } while (arr[i] < p);

        // Find rightmost smaller element than pivot
        do
        {
            j--;
        } while (arr[j] > p);

        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}

void qSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h);
        qSort(arr, l, p);
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