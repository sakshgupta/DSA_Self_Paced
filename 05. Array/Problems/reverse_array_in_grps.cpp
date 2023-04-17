//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    void reverseInGroups(vector<long long> &arr, int n, int k)
    {

        for (int i = 0; i < n; i = i + k)
        {
            int left = i;
            int right = i + k - 1;

            if (right > n - 1)
                right = n - 1;  
            while (left < right)
            {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int n;
    cin >> n;
    vector<long long> arr;
    int k;
    cin >> k;

    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        arr.push_back(x);
    }
    Solution ob;
    ob.reverseInGroups(arr, n, k);

    for (long long i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}