#include <iostream>
#include <climits>
using namespace std;

void mine(int arr[], int n)
{
    int res = INT_MAX, curr_diff = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        if (i == n)
        {
            curr_diff = min(curr_diff, abs(arr[n - 1] - arr[0]));
            res = min(res, curr_diff);
            break;
        }
        curr_diff = min(curr_diff, abs(arr[i - 1] - arr[i]));
        res = min(res, curr_diff);
    }
    cout << res << endl;
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int arr[] = {10, -3, -4, 7, 6, 5, -4, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    mine(arr, n);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}