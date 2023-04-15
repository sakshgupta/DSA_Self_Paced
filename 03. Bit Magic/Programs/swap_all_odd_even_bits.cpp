//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to swap odd and even bits.
    unsigned int swapBits(unsigned int x)
    {
        int m = x & 0xAAAAAAAA; //to get all the even bits 0xAAAAAAAA is 1010 in bin or 10 in dec
        m = m >> 1; // shifting even bits to odd places
        int n = x & 0x55555555; // to get all the odd bits 0x55555555 is 0101 in bin or 5 in dec
        n = n << 1; // shifting odd bits to even places

        int res = m | n; // combining both odd and even bits

        return res;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t; // testcases
    while (t--)
    {
        unsigned int n;
        cin >> n; // input n

        Solution ob;
        // calling swapBits() method
        cout << ob.swapBits(n) << endl;
    }
    return 0;
}
// } Driver Code Ends