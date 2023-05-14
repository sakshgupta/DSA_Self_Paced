#include <bits/stdc++.h>
using namespace std;

void mine(int a1[], int a2[], int m, int n)
{
    unordered_set<int> s(a1, a1 + m);
    for (auto i = 0; i < n; i++)
    {
        if (s.count(a2[i]))
        {
            cout << a2[i] << " ";
            s.erase(a2[i]);
        }
    }
}

// improved efficient approach
void change(int arr[], int n)
{
    unordered_set<int> s(arr, arr + n);
    cout << s.size() << endl;
}

int main()
{
    int a1[] = {10, 20, 10};
    int a2[] = {10, 20, 10};
    int m = sizeof(a1) / sizeof(a1[0]);
    int n = sizeof(a2) / sizeof(a2[0]);
    mine(a1, a2, m, n);
}