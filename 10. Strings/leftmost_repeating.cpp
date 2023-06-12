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
        if (count[str[i]] > 1)
        {
            return i;
        }
    }
    return -1;
}

// improved efficient approach
int efficient(string &str)
{
    const int CHAR = 256;
    int fIndex[CHAR];
    fill(fIndex, fIndex + CHAR, -1);
    int res = INT_MAX;
    for (int i = 0; i < str.length(); i++)
    {
        int fi = fIndex[str[i]];
        if (fi == -1)
            fIndex[str[i]] = i;
        else
        {
            res = min(res, fi);
            fIndex[str[i]] = i;
        }
    }
    return ((res == INT_MAX) ? -1 : res);
}

int efficient2(string &str)
{
    const int CHAR = 256;
    bool visited[CHAR];
    fill(visited, visited + CHAR, false);

    int res = -1;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (visited[str[i]])
            res = i;
        else
            visited[str[i]] = true;
    }
    return res;
}

int main()
{
    string str = "aebccbd";
    cout << efficient2(str);
}