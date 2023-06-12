
#include <bits/stdc++.h>
using namespace std;

void filllps(string &str, int lps[])
{
    int j = 0, i = 1;
    lps[0] = 0;
    while (i < str.length())
    {
        if (str[i] == str[j])
        {
            lps[i] = j + 1;
            j++;
            i++;
        }
        else
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
}

void mine(string &txt, string &pat)
{
    int n = txt.length();
    int m = pat.length();
    int lps[m];
    fill(lps, lps + m, 0);

    filllps(pat, lps);
    int i = 0, j = 0;
    while (i < n)
    {
        if (pat[j] == txt[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << (i - j) << " ";
            j = lps[j - 1];
        }
        else if (i < n and pat[j] != txt[i])
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
}

int main()
{
    // string txt = "ababcababaad";
    // string pat = "ababa";

    string txt = "aaaaab";
    string pat = "aaaa";

    mine(txt, pat);
    return 0;
}
