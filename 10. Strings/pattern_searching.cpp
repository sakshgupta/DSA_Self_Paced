#include <bits/stdc++.h>
using namespace std;

void mine(string &str, string &pat)
{
    int j = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == pat[j])
        {
            int temp = i;
            while (str[temp] == pat[j] and j < pat.length())
            {
                temp++;
                j++;
            }
            if (j == pat.length())
            {
                cout << i << endl;
            }
            j = 0;
        }
    }
}

// improved efficient approach
int efficient(string &str)
{
    const int CHAR = 256;
    int fi[CHAR];
    fill(fi, fi + CHAR, -1);
    int res = INT_MAX;
    for (int i = 0; i < str.length(); i++)
    {
        if (fi[str[i]] == -1)
            fi[str[i]] = i;
        else
            fi[str[i]] = -1;
    }
    for (int i = 0; i < CHAR; i++)
    {
        if (fi[i] >= 0)
            res = min(res, fi[i]);
    }
    return (res == INT_MAX) ? -1 : res;
}

int main()
{
    // string str = "GEEKSFORGEEKS";
    // string pat = "EKS";
    string str = "AAAAA";
    string pat = "AAAB";
    mine(str, pat);
}