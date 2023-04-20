#include <bits/stdc++.h>
using namespace std;

int mine(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // Check if element (mid+1) is minimum element.
        if (mid < high && arr[mid] > arr[mid + 1])
        {
            return arr[mid + 1];
        }
        // Check if mid itself is minimum element
        if (mid > low && arr[mid - 1] > arr[mid])
        {
            return arr[mid];
        }
        // Decide whether we need to go to left half or right half
        else
        {
            if (arr[high] > arr[mid])
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
    }
    return arr[0];
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << mine(arr, n);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}