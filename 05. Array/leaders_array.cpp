#include <iostream>
using namespace std;

void mine(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int flag = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
            cout << arr[i] << " ";
    }
}

void efficient(int arr[], int n)
{
    int curr_ldr = arr[n - 1];
    cout << curr_ldr << " ";
    for (int i = n - 2; i > 0; i--)
    {
        if (arr[i] > curr_ldr)
        {
            curr_ldr = arr[i];
            cout << curr_ldr << " ";
        }
    }
}

int main()
{
    int arr[] = {7, 10, 4, 3, 6, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    // mine(arr, n);
    efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}