#include <iostream>
using namespace std;

void on2(int arr[], int n, int k)
{
    int maxsum = 0, sum = 0;
    for (int i = 0; i + k - 1 < n; i++)
    {
        sum = 0;
        for (int j = 0; j < k; j++)
        {
            sum += arr[i + j];
        }
        maxsum = max(maxsum, sum);
    }
    cout << maxsum << endl;
}

void efficient(int arr[], int n, int k)
{
    int currsum = 0;
    for (int i = 0; i < k; i++)
    {
        currsum += arr[i];
    }
    int maxsum = currsum;
    for (int i = k; i < n; i++)
    {
        currsum += (arr[i] - arr[i - k]);
        maxsum = max(maxsum, currsum);
    }
    cout << maxsum << endl;
}

void subarray_with_given_sum(int arr[], int n, int s)
{
    int start = 0, flag = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        while (sum > s)
        {
            sum -= arr[start];
            start++;
        }
        if (sum == s)
        {
            cout << start << " " << i << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        cout << true << endl;
    else
        cout << false << endl;
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int arr[] = {1, 4, 20, 3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    // on2(arr, n, 3);
    // efficient(arr, n, 3);
    subarray_with_given_sum(arr, n, 33);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}