#include <iostream>
using namespace std;

int main()
{
    int arr[] = {3, 5, 5, 0, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];
    temp[0] = arr[0];
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (temp[res - 1] != arr[i])
        {
            temp[res] = arr[i];
            res++;
        }
    }
    cout << res << endl;
    for (int k = 0; k < n; k++)
    {
        arr[k] = temp[k];
        cout << arr[k] << " ";
    }
}