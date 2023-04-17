#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 0, index = 0;
    cin >> x;
    cin >> index;
    for (int i = n - 1; i >= index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = x;
    cout << "Array after insertion is:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}