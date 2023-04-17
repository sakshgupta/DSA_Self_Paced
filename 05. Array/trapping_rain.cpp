#include <iostream>
using namespace std;

int *f(int arr[], int n)
{
    static int a[2];
    int max = 0;
    int smax = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[max])
        {
            smax = max;
            max = i;
        }
        else if (arr[i + 1] == arr[max])
            smax = i;
        else if (arr[i] != arr[max])
        {
            if (smax == -1)
                smax = i;
            if (arr[i] > arr[smax])
                smax = i;
        }
    }
    a[0] = max;
    a[1] = smax;
    return a;
}

// doesnt solve the corner case of {2, 0, 2}
void mine(int arr[], int n)
{
    int *maxes = f(arr, n);
    cout << maxes[0] << " " << maxes[1] << endl;
    int res = 0;
    for (int i = min(maxes[0], maxes[1]) + 1; i < max(maxes[0], maxes[1]); i++)
    {
        res = res + (arr[maxes[1]] - arr[i]);
    }
    cout << res << endl;
}

void on2(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int lmax = arr[i];
        for (int j = 0; j < i; j++)
        {
            lmax = max(lmax, arr[j]);
        }
        int rmax = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            rmax = max(rmax, arr[j]);
        }
        res = res + (min(lmax, rmax) - arr[i]);
    }
    cout << res << endl;
}
void efficient(int arr[], int n)
{
    int res = 0;
    int lmax[n], rmax[n];
    lmax[0] = arr[0];
    for (int i = 1; i < n; i++)
        lmax[i] = max(lmax[i - 1], arr[i]);

    rmax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rmax[i] = max(rmax[i + 1], arr[i]);

    for (int i = 0; i < n - 1; i++)
        res += (min(rmax[i], lmax[i]) - arr[i]);

    cout << res << endl;
}

int main()
{
    // int arr[] = {2, 0, 2};
    int n;

    // size of array
    cin >> n;

    int arr[n];

    // adding elements to the array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // mine(arr, n);
    // on2(arr, n);
    efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}