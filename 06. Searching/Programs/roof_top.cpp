//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(int arr[], int n)
    {
        if (n == 1)
            return 0;
        int step = 1, maxstep = 0;
        for (int i = 1; i < n; i++)
        {
            if (step < 0)
                step = 0;
            if (arr[i] < arr[i + 1] and i != n - 1)
            {
                step++;
                maxstep = max(maxstep, step);
            }
            else
            {
                step = 0;
            }
        }
        return maxstep;
    }
};

//{ Driver Code Starts.

int main()
{
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    Solution ob;
    cout << ob.maxStep(a, n) << endl;

    return 0;
}
// } Driver Code Ends