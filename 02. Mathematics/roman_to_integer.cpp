#include <iostream>
using namespace std;

int getinteger(char c)
{
    switch (c)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return -1;
    }
}

int romanToInt(string s)
{
    int curr = 0, next = 0, sum = 0, n = s.size(), i = 0;
    cout << n << endl;
    while (i < n)
    {
        if (i == n - 1)
        {
            sum += getinteger(s[i]);
            return sum;
        }
        curr = getinteger(s[i]);
        next = getinteger(s[i + 1]);
        if (curr >= next)
        {
            sum += curr;
            i++;
        }
        else
        {
            sum += next - curr;
            i += 2;
        }
    }
    return sum;
}

int main()
{
    string s = "IV";
    cout << romanToInt(s) << endl;
}
