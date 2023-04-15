#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
vector<string> AllParenthesis(int n);

class Solution
{
public:
        vector<string> AllParenthesis(int n, int o = 0, int c = 0, string s = "")
    {
        if (o == n && c == n)
        {
            ans.push_back(s);
            return ans;
        }
        if (o > c)
        {
            AllParenthesis(n, o, c + 1, s + ")");
        }
        if (o < n)
        {
            AllParenthesis(n, o + 1, c, s + "(");
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int n;
    cin >> n;
    Solution ob;
    vector<string> result = ob.AllParenthesis(n);
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << "\n";
    return 0;
}

// } Driver Code Ends