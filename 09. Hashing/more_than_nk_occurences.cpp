#include <bits/stdc++.h>
using namespace std;

void mine(int arr[], int n, int k)
{
    unordered_set<int> temp;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (m[arr[i]] > n / k)
        {
            temp.insert(arr[i]);
        }
    }
    for (auto it = temp.begin(); it != temp.end(); it++)
    {
        cout << (*it) << " ";
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

// Good for only small 'k's
void improved(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        if (m.count(arr[i]))
            m[arr[i]]++;
        else if (m.size() < k - 1)
            m.insert({arr[i], 1});
        else
        {
            for (auto it = m.begin(); it != m.end();)
            {
                it->second--;
                if (it->second == 0)
                {
                    it = m.erase(it);
                }
                else
                    ++it;
            }
        }
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        int c = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == it->first)
            {
                c++;
            }
        }
        if (c > n / k)
            cout << it->first << " ";
    }
}

int main()
{
    int a1[] = {30, 10, 20, 30, 30, 40, 30, 40, 30};
    int n = sizeof(a1) / sizeof(a1[0]);
    improved(a1, n, 4);
}