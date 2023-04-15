//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxConsecutiveOnes(int n)
    {
        int i = 0;
        while (n)
        {
            n = n & (n << 1); // This operation reduces length of every sequence of 1s by one.
            i++;
        }
        return i;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t; // testcases
    while (t--)
    {
        int n;
        cin >> n; // input n
        Solution obj;
        // calling maxConsecutiveOnes() function
        cout << obj.maxConsecutiveOnes(n) << endl;
    }
    return 0;
}
// } Driver Code Ends