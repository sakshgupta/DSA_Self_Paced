#include <bits/stdc++.h>
using namespace std;

void mine(int a1[], int a2[], int n)
{
    unordered_map<int, int> s;
    int arr[n];
    int presum = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] = a1[i] - a2[i];
    }
    for (int i = 0; i < n; i++)
    {
        presum += arr[i];
        if (s.count(presum))
        {
            res = max(res, i - s[presum]);
        }
        if (s.find(presum) == s.end())
            s.insert({presum, i});
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
    int a1[] = {0, 0, 1, 0};
    int a2[] = {1, 1, 1, 1};
    int n = sizeof(a1) / sizeof(a1[0]);
    mine(a1, a2, n);
}