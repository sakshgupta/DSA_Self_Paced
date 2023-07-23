#include <bits/stdc++.h>

using namespace std;

bool matching(char a, char b)
{
    return ((a == '(' and b == ')') or (a == '{' and b == '}') or (a == '[' and b == ']'));
}

bool mine(const string &str)
{
    stack<char> s;

    for (const auto c : str)
    {
        if (c == '(' or c == '{' or c == '[')
        {
            s.push(c);
        }
        else
        {
            if (s.empty())
                return false;
            if (matching(s.top(), c) == false)
                return false;
            else
                s.pop();
        }
    }

    return s.empty();
}

int main()
{
    string str = "{[(])}";
    cout << mine(str) << endl; // prints true
}
