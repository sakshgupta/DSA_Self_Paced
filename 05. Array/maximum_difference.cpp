#include <iostream>
using namespace std;

void mine(int arr[], int n)
{
    int diff = arr[1] - arr[0];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] - arr[i] > diff)
            {
                diff = arr[j] - arr[i];
            }
        }
    }
    cout << diff << endl;
}

void efficient(int arr[], int n)
{
    int diff = arr[1] - arr[0], minValue = arr[0];
    for (int i = 1; i < n; i++)
    {
        diff = max(diff, arr[i] - minValue);
        minValue = min(minValue, arr[i]);
    }
    cout << diff << endl;
}

int main()
{
    int arr[] = {30, 10, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    // mine(arr, n);
    efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}