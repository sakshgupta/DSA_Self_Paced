#include <bits/stdc++.h>
using namespace std;

int mine(string &str)
{
    const int CHAR = 256;
    int count[CHAR] = {0};
    for (int i = 0; i < str.length(); i++)
    {
        count[str[i]]++;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (count[str[i]] == 1)
            return i;
    }
    return -1;
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

// this wont work for all repeating characters
int trying(string &str)
{
    const int CHAR = 256;
    int res = 0;
    bool visited[CHAR];
    fill(visited, visited + CHAR, false);
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (visited[str[i]] == false)
        {
            visited[str[i]] = true;
            res = i;
        }
    }
    return res;
}

int main()
{
    string str = "abcac";
    cout << trying(str);
}