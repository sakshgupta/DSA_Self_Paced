#include <iostream>
using namespace std;

int main()
{
    int arr[] = {3, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = 0;
    int res = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[max])
        {
            res = max;
            max = i;
        }
        else if (arr[i] != arr[max])
        {
            if (res == -1)
                res = i;
            if (arr[i] > arr[res])
                res = i;
        }
    }
    cout << max << " " << res << endl;
}