#include <bits/stdc++.h>
using namespace std;

void mine(string &str)
{
    int start = 0;
    for (int end = 0; end < str.length(); end++)
    {
        if (str[end] == ' ')
        {
            reverse(str.begin() + start, str.begin() + end);
            start = end + 1;
        }
    }
    reverse(str.begin() + start, str.end());
    reverse(str.begin(), str.end());
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
    string str = "Welcome";
    cout << str << endl;
    mine(str);
    cout << str << endl;
}