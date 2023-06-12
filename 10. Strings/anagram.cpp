#include <bits/stdc++.h>
using namespace std;

bool mine(string &s1, string &s2)
{
    if (s1.length() != s2.length())
        return false;
    unordered_map<char, int> m;
    for (auto ch : s1)
    {
        m[ch]++;
    }
    for (auto ch : s2)
    {
        if (m[ch] == 0)
            return false;
        m[ch]--;
    }
    return true;
}

// improved efficient approach
bool efficient(string &s1, string &s2)
{
    const int CHAR = 256;
    if (s1.length() != s2.length())
        return false;
    int count[CHAR] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }
    for (int i = 0; i < CHAR; i++)
    {
        if (count[i] != 0)
            return false;
    }
    return true;
}

int main()
{
    string str = "aac";
    string s2 = "baa";
    cout << efficient(str, s2);
}