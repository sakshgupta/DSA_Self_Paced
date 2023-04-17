#include <iostream>
using namespace std;

int mine(int arr[], int start, int end)
{
    if (end <= start)
        return 0;
    int profit = 0;
    for (int i = start; i < end; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {
            if (arr[j] > arr[i])
            {
                int curr_profit = arr[j] - arr[i] + mine(arr, start, i - 1) + mine(arr, j + 1, end);
                profit = max(profit, curr_profit);
            }
        }
    }
    return profit;
}

void efficient(int arr[], int n)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            profit += (arr[i] - arr[i - 1]);
        }
    }
    cout << profit << endl;
}

int main()
{
    int arr[] = {1, 5, 3, 1, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << mine(arr, 0, n - 1) << endl;
    efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}