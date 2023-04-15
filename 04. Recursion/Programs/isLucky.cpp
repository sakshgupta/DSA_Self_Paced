#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isLucky(int n)
    {
        static int i = 2;
        if (n < i)
            return 1;
        else if (n % i == 0)
            return 0;
        i++;
        return (isLucky(n - (n / i))); //here we remove n/2, n/2, n/4,... from n to get the new position 
    }
};

//{ Driver Code Starts.
signed main()
{
    int n;
    cin >> n;
    Solution obj;
    // calling isLucky() function
    if (obj.isLucky(n))
        cout << "1\n"; // printing "1" if isLucky() returns true
    else
        cout << "0\n"; // printing "0" if isLucky() returns false
}
// } Driver Code Ends