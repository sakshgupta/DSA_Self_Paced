#include <iostream>
using namespace std;

void naive(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == a[i])
                count++;
        }
        if (count % 2 != 0)
            cout << a[i] << endl;
    }
}

int efficient(int a[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        res = res ^ a[i];
    return res;
}

int main()
{
    int a[] = {4, 3, 4, 4, 5, 5};
    int n = sizeof(a) / sizeof(int);
    // naive(a, n);
    cout << efficient(a, n);
    return 0;
}