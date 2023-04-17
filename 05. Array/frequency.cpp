#include <iostream>
using namespace std;

void mine(int arr[], int n)
{
    int temp = arr[0], c = 1;
    for (int i = 0; i < n; i++)
    {
        temp = arr[i];
        if (arr[i + 1] == temp)
        {
            c++;
        }
        else
        {
            cout << arr[i] << "->" << c << endl;
            c = 1;
        }
    }
}

// void efficient(int arr[], int n)
// {
//     int diff = arr[1] - arr[0], minValue = arr[0];
//     for (int i = 1; i < n; i++)
//     {
//         diff = max(diff, arr[i] - minValue);
//         minValue = min(minValue, arr[i]);
//     }
//     cout << diff << endl;
// }

int main()
{
    int arr[] = {40};
    int n = sizeof(arr) / sizeof(arr[0]);
    mine(arr, n);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}