//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int factorial(int N)
    {
        long long int res = 1;
        for (int i = N; i > 0; i--)
        {
            res *= i;
        }
        return res;
    }

    int facDigits(int N)
    {
        // long long int fact = factorial(N);
        // long long int c = 0;
        // cout << fact << endl;
        // while (fact != 0)
        // {
        //     c++;
        //     cout << fact % 10 << "  ";
        //     fact /= 10;
        // }
        // return c;
        double r = 0;
        for (int i = 2; i <= N; i++)
        {
            r = r + log10(i);
        }
        return floor(r) + 1;
    }
};

//{ Driver Code Starts.
int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {

    int n;
    cin >> n;
    Solution ob;
    cout << "\n"
         << ob.facDigits(n) << "\n";
    // }
    return 0;
}
// } Driver Code Ends