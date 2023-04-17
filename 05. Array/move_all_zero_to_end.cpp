#include <iostream>
using namespace std;

// Mine naive code
// int main()
// {
//     int arr[] = {3, 5, 0, 6, 0, 8};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == 0)
//         {
//             for (int j = i; j < n; j++)
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
//     for (int k = 0; k < n; k++)
//     {
//         cout << arr[k] << " ";
//     }
// }

// Efficient Solution
int main()
{
    int arr[] = {3, 5, 0, 4, 0, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[c]);
            c++;
        }
    }
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}