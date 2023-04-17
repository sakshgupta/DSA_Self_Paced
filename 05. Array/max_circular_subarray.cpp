#include <iostream>
using namespace std;

void mine(int arr[], int n)
{
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
        int curr_sum = arr[i];
        int curr_max = arr[i];
        for (int j = 1; j < n; j++)
        {
            int index = (i + j) % n;
            curr_sum += arr[index];
            curr_max = max(curr_max, curr_sum);
        }
        res = max(res, curr_max);
    }
    cout << res << endl;
}

// Efficient Solution:-
int totalarraysum(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += arr[i];
    }
    return res;
}

int maxsum(int arr[], int n)
{
    int res = arr[0];
    int maxending = arr[0];
    for (int i = 0; i < n; i++)
    {
        maxending = min(maxending + arr[i], arr[i]);
        res = min(res, maxending);
    }
    return res;
}

int minsum(int arr[], int n)
{
    int res = arr[0];
    int minending = arr[0];
    for (int i = 0; i < n; i++)
    {
        minending = min(minending + arr[i], arr[i]);
        res = min(res, minending);
    }
    return res;
}

void on(int arr[], int n)
{
    int res = max(maxsum(arr, n), (totalarraysum(arr, n) - minsum(arr, n)));
    cout << res << endl;
}

void efficient(int arr[], int n)
{
    int maxnormal = maxsum(arr, n);
    if (maxnormal < 0)
        cout << maxnormal << endl;
    int arrsum = 0;
    for (int i = 0; i < n; i++)
    {
        arrsum += arr[i]; // Calculating total array sum
        arr[i] = -arr[i]; // Inverting the array to find the minsum of the subarray using the same maxsum function
    }
    int maxcircular = arrsum + maxsum(arr, n);
    cout << max(maxcircular, maxnormal);
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int arr[] = {-3, -2, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    // mine(arr, n);
    on(arr, n);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}