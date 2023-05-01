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
        if (j > 0 and b[j] == b[j - 1])
        {
            j++;
            continue;
        }
        if (a[i] == b[j])
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else if (a[i] > b[j])
        {
            cout << b[j] << " ";
            j++;
        }
    }

    while (i < m)
    {
        if (a[i] != a[i - 1])
            cout << a[i] << " ";
        i++;
    }
    while (j < n)
    {
        if (b[j] != b[j - 1])
            cout << b[j] << " ";
        j++;
    }
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int a[] = {1, 4, 18, 19, 19, 28, 29, 32, 35, 35, 39, 39, 44, 49, 49, 50, 50};
    int b[] = {8, 34};
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