#include <bits/stdc++.h>

using namespace std;

// ^ -> 3, *, / -> 2, +, - -> 1
int get_precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

string mine(string str)
{
    stack<char> s;
    int n = str.length();
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        // if operand or a digit
        if (isalnum(str[i]))
        {
            ans += str[i];
        }
        // if left paranthesis
        else if (str[i] == '(')
        {
            s.push(str[i]);
        }
        // if right paranthesis
        else if (str[i] == ')')
        {
            // until u find '('
            while (!s.empty() && s.top() != '(')
            {
                ans += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(')
                s.pop();
        }
        // if operator
        else
        {
            // if current string operators precendence is less than the stack's top operator's precedence
            while (!s.empty() && get_precedence(str[i]) <= get_precedence(s.top()))
            {
                ans += s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }
    // pop out everything and append to answer
    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }
    return ans;
}

int main()
{
    string str = "h^m^q^(7-4)";
    cout << mine(str) << endl;
    return 0;
}
