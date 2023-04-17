#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int d = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];
    int k = 0;
    for (int i = d; i < n; i++)
    {
        temp[k] = arr[i];
        k++;
    }
    for (int i = 0; i < d; i++)
    {
        temp[k] = arr[i];
        k++;
    }
    for (int k = 0; k < n; k++)
    {
        arr[k] = temp[k];
        cout << temp[k] << " ";
    }
}