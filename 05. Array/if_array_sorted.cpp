#include <iostream>
using namespace std;

int main()
{
    int arr[] = {3, 5, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int flag = true;
    if (n == 1)
        cout << 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            flag = false;
            break;
        }
    }
    if (flag == false)
        cout << 0;
    else
        cout << 1;
}