#include <iostream>
using namespace std;

void mine(int arr[], int n)
{
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        j = i - 1;
        while (key < arr[j] and j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
            // cout << j << endl;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int arr[] = {10, 5, 8, 20, 2, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    mine(arr, n);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}