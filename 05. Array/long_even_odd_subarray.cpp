#include <iostream>
using namespace std;

void mine(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = 1;
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[j - 1] % 2 == 0 && arr[j] % 2 != 0) || (arr[j - 1] % 2 != 0 && arr[j] % 2 == 0))
                curr++;
            else
                break;
        }
        res = max(res, curr);
    }
    cout << res << endl;
}

void efficient(int arr[], int n)
{
    int res = 1, curr = 1;
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0) || (arr[i] % 2 != 0 && arr[i - 1] % 2 == 0))
        {
            curr++;
            res = max(res, curr);
        }
        else
            curr = 1;
    }
    cout << res << endl;
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int arr[] = {7, 10, 13, 11, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    // mine(arr, n);
    efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}