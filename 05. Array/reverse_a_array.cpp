#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 5, 7, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp = 0;
    cout << "Before" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
    int i, j;
    for (i = 0, j = n - 1; i < n / 2; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    cout << "\nAfter" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}