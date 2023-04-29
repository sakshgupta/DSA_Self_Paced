#include <iostream>
using namespace std;

void mine(int arr[], int l, int h)
{
    int p = arr[h];
    int i = l - 1;
    for (int j = l; j <= h-1; j++)
    {
        if (arr[j] < p)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    cout << (i + 1) << endl;
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int a[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(a) / sizeof(a[0]);
    mine(a, 0, n - 1);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << " ";
    }
}