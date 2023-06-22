#include <bits/stdc++.h>
using namespace std;

#define CHAR 256

unsigned long long fact(int n)
{
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int mine(string &str)
{
    int res = 1;
    int n = str.length();
    int count[CHAR] = {0};
    int mul = fact(n);

    for (int i = 0; str[i]; ++i)
        ++count[str[i]];

    for (int i = 1; i < CHAR; ++i)
        count[i] += count[i - 1];

    for (int i = 0; i < n; i++)
    {
        mul = mul / (n - i);
        res += (count[str[i] - 1] * mul);
        for (int j = str[i]; j < CHAR; j++)
        {
            --count[j];
        }
    }
    return res;
}

// improved efficient approach
bool efficient(string &s1, string &s2)
{
    return false;
}

int main()
{
    string str = "xzbcoejuvp";
    cout << mine(str);
}