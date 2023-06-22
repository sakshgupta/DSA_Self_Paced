
#include <bits/stdc++.h>
using namespace std;

void mine(string &str)
{
    int j = 0, i = 1;
    vector<int> lps(str.length(), 0);
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
    for (int i = 0; i < lps.size(); i++)
    {
        cout << lps[i] << " ";
    }
}

int main()
{
    // char txt[] = "ABDCB";
    // char pat[] = "DC";

    string str = "abcbabca";

    mine(str);
    return 0;
}
