#include <bits/stdc++.h>
using namespace std;

void mine(int arr[], int n, int k)
{
    vector<vector<int>> v(k);
    for (int i = 0; i < n; i++)
    {
        int pos = arr[i] % k;
        v[pos].push_back(arr[i]);
    }
    for (int i = 0; i < k; i++)
    {
        cout << i << "->";
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << "->";
        }
        cout << endl;
    }
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
    int a1[] = {92, 4, 14, 24, 44, 91};
    int n = sizeof(a1) / sizeof(a1[0]);
    mine(a1, n, 10);
}