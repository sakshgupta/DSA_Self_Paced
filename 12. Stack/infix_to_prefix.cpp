#include <bits/stdc++.h>

using namespace std;

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '/':
    case '*':
        return 2;
        break;
    case '^':
        return 3;
        break;
    default:
        return -1;
        break;
    }
}

string reverse(string &str)
{
    int low = 0, high = str.length() - 1;
    while (low < high)
    {
        swap(str[low], str[high]);
        low++;
        high--;
    }
    return str;
}

string mine(string str)
{
    stack<char> s;
    string ans = "";

    // * traversing from right to left
    for (int i = str.length() - 1; i >= 0; i--)
    {
        int ch = str[i];
        // if its an operand
        if (isalnum(ch))
        {
            ans += ch;
        }
        // if its right paranthesis
        else if (ch == ')')
        {
            s.push(ch);
        }
        // if its left paranthesis
        // * now doing poping and appending till we find left paranthesis
        else if (ch == '(')
        {
            while (!s.empty() and s.top() != ')')
            {
                int temp = s.top();
                s.pop();
                ans += temp;
            }
            if (!s.empty() and s.top() == ')')
            {
                s.pop();
            }
        }
        // if its an operator
        else
        {
            // while ch's precedence is less than the s.top's
            while (!s.empty() and (precedence(ch) < precedence(s.top()) or ch == '^'))
            {
                int temp = s.top();
                s.pop();
                ans += temp;
            }
            s.push(ch);
        }
    }
    // popping out everthing
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        ans += temp;
    }
    // reverse the answer
    ans = reverse(ans);
    return ans;
}

int main()
{
    string str = "x^y^z";
    cout << mine(str) << endl;
    return 0;
}
