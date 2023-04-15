//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int binaryToGray(int n)
    {
        return n ^ (n >> 1);
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int n;
    cin >> n; // initializing n

    Solution ob;
    // calling function grayToBinary()
    cout << ob.binaryToGray(n) << endl;
}

// } Driver Code Ends