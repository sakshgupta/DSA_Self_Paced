//{ Driver Code Starts
// C++ program to check if two strings are isomorphic

#include <bits/stdc++.h>

using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
public:
    // Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {

        // we are storing the last index of the all characters in a sarr and warr array then just checking if str1 elements's last index is same as str2 element`
        if (str1.length() != str2.length())
        {
            return false;
        }
        int sarr[26] = {0};
        int warr[26] = {0};

        for (int i = 0; i < str1.length(); i++)
        {
            sarr[str1[i] - 'a'] = i + 1;
            warr[str2[i] - 'a'] = i + 1;
        }
        for (int j = 0; j < str1.length(); j++)
        {
            if (sarr[str1[j] - 'a'] != warr[str2[j] - 'a'])
            {
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    Solution obj;
    cout << obj.areIsomorphic(s1, s2) << endl;

    return 0;
}
// } Driver Code Ends