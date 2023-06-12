#include <bits/stdc++.h>
using namespace std;

#define CHAR 256

bool mine(string &s1, string &s2)
{
    int count[CHAR] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        count[s1[i]]++;
    }
    for (int i = 0; i < s2.length(); i++)
    {
        if (count[s2[i]] == 0)
            return false;
    }
    return true;
}

bool areSame(int *arr1, int *arr2)
{
    for (int i = 0; i < CHAR; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}

// improved efficient approach
bool efficient(string &s1, string &s2)
{
    int CT[CHAR] = {0}, CP[CHAR] = {0};
    for (int i = 0; i < s2.length(); i++)
    {
        CT[s1[i]]++;
        CP[s2[i]]++;
    }
    for (int i = s2.length(); i < s1.length(); i++)
    {
        if (areSame(CT, CP))
        {
            return true;
        }
        CT[s1[i]]++;
        CT[s1[i - s2.length()]]--;
    }
    return false;
}

int main()
{
    string str = "geeksforgeeks";
    string s2 = "frog";
    cout << efficient(str, s2);
}