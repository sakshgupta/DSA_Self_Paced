//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int posOfRightMostDiffBit(int m, int n)
    {
        int count = 0;
        if (m == 0 & n == 0)
            return -1;
        else if (m == n)
            return -1;
        if (m == 0 && n == 0)
            return -1;
        if (m == 0 && n != 0)
        {
            int i = 0;
            while (n)
            {
                if (n % 2 == 1)
                    return i + 1;
                n = n / 2;
                i++;
            }
        }
        if (m != 0 && n == 0)
        {
            int i = 0;
            while (m)
            {
                if (m % 2 == 1)
                    return i + 1;
                m = m / 2;
                i++;
            }
        }
        int i = 0;
        while (m || n)
        {
            if (m % 2 == 1 && n % 2 == 0)
                return i + 1;
            else if (m % 2 == 0 && n % 2 == 1)
                return i + 1;
            i++;
            m = m / 2;
            n = n / 2;
        }
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t; // input number of testcases
    while (t--)
    {
        int m, n;
        cin >> m >> n; // input m and n
        Solution ob;
        cout << ob.posOfRightMostDiffBit(m, n) << endl;
    }
    return 0;
}
// } Driver Code Ends