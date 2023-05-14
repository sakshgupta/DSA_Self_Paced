#include <bits/stdc++.h>
using namespace std;

void mine(int arr[], int n)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    cout << s.size() << endl;
}

// improved efficient approach
void change(int arr[], int n)
{
    unordered_set<int> s(arr, arr+n);
    cout << s.size() << endl;
}

int main()
{
    int arr[] = {10, 10, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    change(arr, n);
}