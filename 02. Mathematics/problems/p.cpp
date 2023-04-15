#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isPrime(int n)
    {
        assert(n > 0);
        if (n <= 3)
            return n > 1;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i += 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        return true;
    }

    int exactly3Divisors(long long int n)
    {
        cout << n << endl;
        if (n <= 3)
            return 5;
        int count = 0;
        for (int i = 2; i * i <= n; ++i)
        {
            if (isPrime(i))
            {
                ++count;
            }
        }
        return count;
    }

    vector<int> threeDivisors(vector<long long> query, int q)
    {
        vector<int> three;
        long long int ele = 0;
        for (auto &ele : query)
        {
            cout << ele << endl;
            three.push_back(exactly3Divisors(ele));
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
        cout << cnt << endl;
    }

    return 0;
}
// } Driver Code Ends