//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
private:
    void f(int i, int tar, vector<vector<int>> &res, vector<int> &ds, vector<int> &arr)
    {
        if (i == arr.size())
        {
            if (tar == 0)
            {
                res.push_back(ds);
            }
            return;
        }
        if (arr[i] <= tar)
        {
            ds.push_back(arr[i]);
            f(i, tar - arr[i], res, ds, arr);
            ds.pop_back();
        }
        f(i + 1, tar, res, ds, arr);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &A, int B)
    {
        sort(A.begin(), A.end());
        vector<vector<int>> res;
        vector<int> ds;

        // did this to remove duplicates in the original vector A
        int i = 0;

        vector<int> c;
        for (int j = 0; j < A.size() - 1; j++)
        {
            if (A[j] != A[j + 1])
                c.push_back(A[j]);
        }

        c.push_back(A[A.size() - 1]);

        f(0, B, res, ds, c);
        if (res.size() == 0)
            return res;

        sort(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int n;
    cin >> n;
    vector<int> A;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    int sum;
    cin >> sum;
    Solution ob;
    vector<vector<int>> result = ob.combinationSum(A, sum);
    if (result.size() == 0)
    {
        cout << "Empty";
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << '(';
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j < result[i].size() - 1)
                cout << " ";
        }
        cout << ")";
    }
    cout << "\n";
}
// } Driver Code Ends