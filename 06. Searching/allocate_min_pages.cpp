#include <iostream>
using namespace std;

// To check if the ans is feasible or not by checking the number of students required is less than k
bool isFeasible(int arr[], int n, int k, int ans)
{
    int req = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] > ans)
        {
            req++;
            sum = arr[i];
        }
        else
            sum += arr[i];
    }
    return (req <= k);
}

int mine(int arr[], int n, int k)
{
    int sum = 0, mx = 0;
    // Calculating max element and sum
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        mx = max(mx, arr[i]);
    }
    // Binary Search
    int low = mx, high = sum, res = 0;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (isFeasible(arr, n, k, mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int arr[] = {12, 34, 67, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << mine(arr, n, 5);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}