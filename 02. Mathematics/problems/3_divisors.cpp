#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int divisors(int n)
    {
        int c = 0, j = 0;
        cout << "N=" << n << endl;
        for (j = 1; j * j < n; j++)
        {
            if (n % j == 0)
            {
                c++;
                cout << j << " ";
            }
        }
        for (; j >= 1; j--)
        {
            if (n % j == 0)
            {
                c++;
                cout << n / j << " ";
            }
        }
        return c;
    }

    vector<int> threeDivisors(vector<long long> query, int q)
    {
        int n = 0, x = 0;
        vector<int> three;
        for (auto &ele : query)
        {
            n = 0;
            x = 0;
            for (int i = ele; i > 3; i--)
            {
                n = divisors(i);
                cout << "\n"
                     << n << endl;
                if (n == 3)
                    x++;
            }
            three.push_back(x);
        }
        return three;
    }
};

//{ Driver Code Starts.
int main()
{
    int q;
    cin >> q;
    vector<long long> query(q);
    for (int i = 0; i < q; i++)
    {
        cin >> query[i];
    }
    Solution ob;

    vector<int> ans = ob.threeDivisors(query, q);
    for (auto cnt : ans)
    {
        cout << "\n"
             << cnt << endl;
    }

    return 0;
}
// } Driver Code Ends