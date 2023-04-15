//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<double> FindRoots(int a, int b, int c)
    {
        vector<double> res;
        int d = b * b - 4 * a * c;
        double sqrt_val = sqrt(abs(d));
        if (d < (double)0)
            return vector<double>(1, -1);
        res.push_back((double)(-b + sqrt_val) / (2 * a));
        res.push_back((double)(-b - sqrt_val) / (2 * a));
        if (res[1] < res[0])
            swap(res[0], res[1]);
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    // int tc;
    // cin >> tc;
    // while (tc--)
    // {
    int A, B, C;
    cin >> A >> B >> C;
    Solution obj;
    vector<double> ans = obj.FindRoots(A, B, C);
    if (ans.size() == 1)
    {
        cout << (int)ans[0] << "\n";
        // continue;
    }
    for (auto i : ans)
        cout << fixed << setprecision(6) << i << " ";
    cout << "\n";
    // }
    return 0;
}