#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    void persum(int arr[], int n, int sum, int i, int s, int &c)
    {
        if (i == n)
        {
            return;
        }
        if (s == sum)
        {
            c++;
            cout << arr[i] << s << i << c << endl;
        }
        persum(arr, n, sum, i + 1, s + arr[i], c);
        persum(arr, n, sum, i + 1, s, c);
    }

public:
    int perfectSum(int arr[], int n, int sum)
    {
        int c = 0;
        persum(arr, n, sum, 0, 0, c);
        return c;
    }
};

//{ Driver Code Starts.
int main()
{
    int n, sum;

    cin >> n >> sum;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Solution ob;
    cout << ob.perfectSum(a, n, sum) << "\n";
    return 0;
}

// } Driver Code Ends