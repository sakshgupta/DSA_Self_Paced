#include <iostream>
using namespace std;

void mine(int arr[], int n)
{
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        res = max(arr[i], arr[i - 1]);
        cout << res << endl;
    }
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int arr[] = {5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    mine(arr, n);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}