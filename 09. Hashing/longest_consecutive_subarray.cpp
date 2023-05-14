#include <bits/stdc++.h>
using namespace std;

void mine(int arr[], int n)
{
    unordered_set<int> s(arr, arr + n);
    int c = 1, res = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = arr[i];
        while (s.find(temp + 1) != s.end())
        {
            c++;
            temp = temp + 1;
        }
        res = max(res, c);
        c = 1;
    }
    cout << res << endl;
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
    int a1[] = {1, 9, 3, 4, 2, 20};
    int n = sizeof(a1) / sizeof(a1[0]);
    efficient(a1, n);
}