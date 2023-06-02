#include <bits/stdc++.h>
using namespace std;

void mine(int arr[], int sum, int n)
{
    unordered_set<int> s;
    s.insert(0);
    int presum = 0;
    for (auto i = 0; i < n; i++)
    {
        presum += arr[i];
        if (s.count(presum - sum))
        {
            cout << "true" << endl;
        }
        s.insert(presum);
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
    int a1[] = {3, 2, 5, 6};
    int n = sizeof(a1) / sizeof(a1[0]);
    mine(a1, 12, n);
}