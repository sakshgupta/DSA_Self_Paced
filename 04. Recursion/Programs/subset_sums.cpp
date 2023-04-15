//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    void f(int i, int sum, vector<int> &ds, vector<int> arr, int n)
    {
        if (i == n)
        {
            ds.push_back(sum);
            return;
        }
        f(i + 1, sum + arr[i], ds, arr, n);
        f(i + 1, sum, ds, arr, n);
    }

public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ds;
        f(0, 0, ds, arr, N);
        return ds;
    }
};

//{ Driver Code Starts.
int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    Solution ob;
    vector<int> ans = ob.subsetSums(arr, N);
    sort(ans.begin(), ans.end());
    for (auto sum : ans)
    {
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}
// } Driver Code Ends