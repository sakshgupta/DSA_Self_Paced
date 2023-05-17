#include <bits/stdc++.h>
using namespace std;

void mine(int arr[], int sum, int n)
{
    unordered_map<int, int> m;
    int presum = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        presum += arr[i];
        // To handle the case if subarray is present at the beginning of the array
        if (presum == sum)
            res = i + 1;
        // To only store the leftmost apprearance of a single element so as to create the longest subarray possible
        if (m.find(presum) == m.end())
            m.insert({presum, i});
        // If the subarray is found then calculate the length of the subarray
        if (m.find(presum - sum) != m.end())
            res = max(res, i - m[presum - sum]);
    }
    cout << res << endl;
}

// improved efficient approach
void change(int arr[], int n)
{
    unordered_set<int> s(arr, arr + n);
    cout << s.size() << endl;
}

int main()
{
    int a1[] = {8, 3, 1, 5, -6, 6, 2, 2};
    int n = sizeof(a1) / sizeof(a1[0]);
    mine(a1, 4, n);
}