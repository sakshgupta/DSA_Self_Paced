#include <bits/stdc++.h>
using namespace std;

void mine(int arr[], int sum, int n)
{
    unordered_set<int> s;
    for (auto i = 0; i < n; i++)
    {
        if (s.count(sum - arr[i]))
        {
            cout << "true" << endl;
        }
        s.insert(arr[i]);
    }
    cout << "false" << endl;
}

// improved efficient approach
void change(int arr[], int n)
{
    unordered_set<int> s(arr, arr + n);
    cout << s.size() << endl;
}

int main()
{
    int a1[] = {11, 5, 6};
    int n = sizeof(a1) / sizeof(a1[0]);
    mine(a1, 10, n);
}