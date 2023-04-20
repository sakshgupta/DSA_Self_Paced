#include <iostream>
#include <climits>
using namespace std;

int mine(int arr[], int n)
{
    int res = 0, c = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[res])
        {
            cout << res << i << endl;
            return arr[res];
        }
        else
            c--;
        if (c == 0)
        {
            c = 1;
            res = i;
        }
    }
    return -1;
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int arr[] = {1, 2, 3, 0, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << mine(arr, n);
    // efficient(arr, n);
    // cout << "\nThe array after function call" << endl;
    // for (int k = 0; k < n; k++)
    // {
    //     cout << arr[k] << " ";
    // }
}