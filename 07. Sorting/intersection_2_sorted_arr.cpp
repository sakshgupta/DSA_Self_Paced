#include <iostream>
using namespace std;

void mine(int a[], int b[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (i > 0 and a[i] == a[i - 1])
        {
            i++;
            continue;
        }
        if (a[i] == b[j])
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
        if (a[i] < b[j])
        {
            i++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
    }
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int a[] = {1, 1, 3, 3, 3};
    int b[] = {1, 1, 1, 1, 1, 3, 5, 7};
    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);
    mine(a, b, m, n);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << " ";
        cout << b[k] << " ";
    }
}