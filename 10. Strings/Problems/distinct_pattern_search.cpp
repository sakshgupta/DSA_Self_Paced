#include <bits/stdc++.h>
using namespace std;

bool mine(string &txt, string &pat)
{
    int n = txt.length();
    int m = pat.length();

    for (int i = 0; i <= n-m;)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (pat[j] != txt[i + j])
                break;
        }
        if (j == m)
            return true;
        if (j == 0)
            i++;
        else
            i += j;
    }
    return false;
}

int main()
{
    string txt = "abceabcdabceabcd";
    string pat = "bcd";
    cout << mine(txt, pat) << endl;
}