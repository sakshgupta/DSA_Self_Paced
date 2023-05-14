#include <bits/stdc++.h>
using namespace std;

void mine(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < k; i++)
    {
        m[arr[i]]++;
    }
    cout << m.size() << " ";
    for (int i = k; i < n; i++)
    {
        m[arr[i - k]]--;
        if (m[arr[i - k]] == 0)
            m.erase(arr[i - k]);
        m[arr[i]]++;
        cout << m.size() << " ";
    }
}

// improved efficient approach
void efficient(int arr[], int n)
{
    unordered_set<int> s(arr, arr + n);
    int c = 1, res = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.count(arr[i] - 1) == 0)
        {
            c = 1;
            while (s.count(arr[i] + c))
            {
                c++;
            }
            res = max(res, c);
        }
    }
    cout << res << endl;
}

int main()
{
    int a1[] = {10, 10, 10, 10};
    int n = sizeof(a1) / sizeof(a1[0]);
    mine(a1, n, 3);
}