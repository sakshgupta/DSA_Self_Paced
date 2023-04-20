#include <iostream>
using namespace std;

bool mine(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        if (arr[low] + arr[high] == x)
        {
            cout << arr[low] << " " << arr[high] << endl;
            return true;
        }
        if (arr[low] + arr[high] > x)
            high = high - 1;
        else
            low = low + 1;
    }
    return false;
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int arr[] = {2, 4, 8, 9, 11, 12, 20, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << mine(arr, n, 23);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}