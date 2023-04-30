#include <iostream>
using namespace std;

void partition(int arr[], int n)
{
    int l = 0, m = 0, h = n - 1;
    while (m <= h)
    {
        if (arr[m] == 0)
        {
            swap(arr[l], arr[m]);
            l++;
            m++;
        }
        else if (arr[m] == 1)
        {
            m++;
        }
        else
        {
            swap(arr[h], arr[m]);
            h--;
        }
    }
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int a[] = {1, 0, 1, 2, 1, 1, 2};
    int n = sizeof(a) / sizeof(a[0]);
    partition(a, n);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << " ";
    }
}