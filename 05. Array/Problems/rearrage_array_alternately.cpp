//{ Driver Code Starts
// C++ program to rearrange an array in minimum
// maximum form
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rearrange(long long *arr, int n)
    {
        // Storing 2 nos in a single array index using divident = divisor + remainder * quotient
        int maxi = n - 1, mini = 0;
        int me = arr[maxi] + 1;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                arr[i] = arr[i] + (arr[maxi] % me) * me;
                maxi--;
            }
            else
            {
                arr[i] = arr[i] + (arr[mini] % me) * me;
                mini++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] /= me;
        }
    }
};

int main()
{
    int n;
    cin >> n;

    long long arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution ob;

    ob.rearrange(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}
