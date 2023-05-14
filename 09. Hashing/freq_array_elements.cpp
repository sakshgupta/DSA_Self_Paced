#include <bits/stdc++.h>
using namespace std;

void mine(int arr[], int n)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for (auto e : m)
    {
        cout << e.first << " " << e.second << endl;
    }
}

// To get the order of keys in which they already were use this function
void change(int arr[], int n)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (m.find(arr[i]) != m.end() and m[arr[i]] != -1)
        {
            cout << arr[i] << " " << m[arr[i]] << endl;
            m[arr[i]] = -1;
        }
    }
}

int main()
{
    int arr[] = {50, 50, 10, 40, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    change(arr, n);
}