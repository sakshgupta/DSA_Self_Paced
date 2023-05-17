#include <bits/stdc++.h>
using namespace std;

void mine(int arr[], int n)
{
    int j = 2, res = 0;
    for (int i = 0; i < n; i++)
    {
        int zeros = 0, ones = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[j] == 0)
                zeros++;
            else
                ones++;
            if (zeros == ones)
                res = max(res, j - i + 1);
        }
    }
    cout << res << endl;
}

// improved efficient approach
void efficient(int arr[], int n)
{
    unordered_map<int, int> s;
    int presum = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            arr[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        presum += arr[i];
        if (s.count(presum))
        {
            res = max(res, i - s[presum]);
        }
        if (presum == 0)
        {
            res = max(res, i + 1);
        }
        s.insert({presum, i});
    }
    cout << res << endl;
}

int main()
{
    int a1[] = {1, 0, 0, 1, 0, 1, 1};
    int n = sizeof(a1) / sizeof(a1[0]);
    efficient(a1, n);
}