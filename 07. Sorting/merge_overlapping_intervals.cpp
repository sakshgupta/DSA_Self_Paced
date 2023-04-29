#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Interval
{
    int start, end;
};

bool mycomp(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}

void mine(Interval arr[], int n)
{
    sort(arr, arr + n, mycomp);
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[res].end >= arr[i].start)
        {
            arr[res].end = max(arr[res].end, arr[i].end);
            arr[res].start = min(arr[res].start, arr[i].start);
        }
        else
        {
            res++;
            arr[res] = arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].start << " " << arr[i].end << endl;
    }
}

int main()
{
    // int arr[] = {-6, -1, -8};
    Interval arr[] = {{1, 3}, {2, 4}, {5, 7}, {6, 8}};
    int n = sizeof(arr) / sizeof(arr[0]);
    mine(arr, n);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    // for (int k = 0; k < n; k++)
    // {
    //     cout << arr[k] << " ";
    // }
}