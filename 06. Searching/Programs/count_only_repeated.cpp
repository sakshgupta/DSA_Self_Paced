#include <iostream>
using namespace std;

int mine(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        // As the array is sorted so the index should contain a specific element like 0->7, 2->8, 3->9(should have but becoz of repeating 8 3->8 but there should be 9 at the place of 8) here is the issue
        // So we find that part where the value is there where it isnt supposed to be
        if (arr[mid] >= (arr[0] + mid))
            low += mid + 1;
        else
            high = mid;
    }
    return arr[low];
    // for the no. of times this repeating element occured do this (n - (a[n - 1] - a[0]))
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int arr[] = {6, 7, 8, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << mine(arr, n);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}