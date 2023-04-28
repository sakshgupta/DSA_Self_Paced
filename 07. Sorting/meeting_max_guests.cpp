#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

void mine(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int i = 1, j = 0, res = 1, curr = 1;
    while (i < n and j < n)
    {
        if (arr[i] <= dep[j])
        {
            curr++;
            i++;
        }
        else
        {
            curr--;
            j++;
        }
        res = max(res, curr);
    }
    cout << res << endl;
}

int main()
{
    // int arr[] = {-6, -1, -8};
    Interval arr[] = {{1, 3}, {2, 4}, {5, 7}, {6, 8}};
    int n = sizeof(arr) / sizeof(arr[0]);
    mine(arr, n);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    // for (int k = 0; k < n; k++)
    // {
    //     cout << arr[k] << " ";
    // }
}