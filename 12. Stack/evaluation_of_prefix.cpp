#include <bits/stdc++.h>

using namespace std;

int mine(string &str)
{
    stack<int> s;

    for (int i = str.length() - 1; i >= 0; i--)
    {
        char ch = str[i];
        if (isdigit(ch))
        {
            int num = 0, base = 1;
            // * handling more than 1 digit numbers
            // ! make sure to use str[i] in this because i will change and so will str[i]
            while (i >= 0 && isdigit(str[i]))
            {
                num += (str[i] - '0') * base;
                base *= 10;
                i--;
            }
            i++;
            s.push(num);
        }
        else if (ch == ' ' or ch == '\t')
            continue;
        else
        {
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            
            // * in this we change the op1 with op2
            switch (ch)
            {
            case '+':
                s.push(op2 + op1);
                break;
            case '-':
                s.push(op2 - op1);
                break;
            case '*':
                s.push(op2 * op1);
                break;
            case '/':
                s.push(op2 / op1);
                break;
            case '^':
                s.push(op2 ^ op1);
                break;
            default:
                break;
            }
        }
    }
    return s.top();
}

int main()
{
    string str = "+ * 10 2 3";
    cout << mine(str) << endl;
    return 0;
}
