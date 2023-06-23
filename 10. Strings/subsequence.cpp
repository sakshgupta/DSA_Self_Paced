#include <bits/stdc++.h>
using namespace std;

bool mine(string &str, string &s2)
{
    int i = 0, j = 0;
    while (i < str.size() and j < s2.size())
    {
        if (str[i] == s2[j])
        {
            i++;
            j++;
        }
        else
            i++;
    }
    return (j == s2.size());
}

// improved efficient approach
bool recurssive(string &str, string &s2, int n, int m)
{
    if (m == 0)
        return true;
    if (n == 0)
        return false;
    if (str[n - 1] == s2[m - 1])
        return recurssive(str, s2, n - 1, m - 1);
    else
        return recurssive(str, s2, n - 1, m);
}

int main()
{
    string str = "abcdasgdsfsdf";
    string s2 = "acb";
    cout << recurssive(str, s2, str.size(), s2.size());
}