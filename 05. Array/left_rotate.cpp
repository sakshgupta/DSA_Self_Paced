#include <iostream>
using namespace std;

int main()
{
    int arr[] = {3, 5, 6, 8, 4, 7, 10, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        swap(arr[i - 1], arr[i]);
    }
    arr[n] = temp;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}