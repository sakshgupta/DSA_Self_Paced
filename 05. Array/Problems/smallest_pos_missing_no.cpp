#include <bits/stdc++.h>
using namespace std;

int mine(int arr[], int n)
{
    int small = INT_MAX;
    if (arr[0] != 0 && arr[0] != 1)
    {
        if (0 - arr[0] != 1)
            small = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0 && arr[i + 1] >= 0)
        {
            if (arr[i + 1] - arr[i] != 1)
            {
                cout << "hello";
                small = min(small, (arr[i] + 1));
            }
            if (i + 1 == n)
                small = min(small, arr[i] + 1);
        }
    }
    return small;
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << mine(arr, arr_size);
    return 0;
}
