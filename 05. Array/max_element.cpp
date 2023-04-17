#include <iostream>
using namespace std;

int main()
{
    int arr[] = {3, 8, 12, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0];
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxi = i;
        }
    }
    cout << max << endl;
}