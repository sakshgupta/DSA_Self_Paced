#include <bits/stdc++.h>
using namespace std;

bool mine(int arr[], int n, int k)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.count(k - arr[i]))
        {
            // auto it = s.find(k - arr[i]);
            return 1;
        }
        s.insert(arr[i]);
    }
    return 0;
}

// improved efficient approach
void efficient(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for (auto e : m)
    {
        if (e.second > n / k)
        {
            cout << e.first << " ";
        }
    }
}

int main()
{
    int a1[] = {2, 5};
    int n = sizeof(a1) / sizeof(a1[0]);
    cout << mine(a1, n, 7);
}