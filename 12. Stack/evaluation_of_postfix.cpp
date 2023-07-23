#include <bits/stdc++.h>

using namespace std;

int mine(string &str)
{
    stack<int> s;

    for (int i = 0; i < str.length(); i++)
    {
        // ? if its a digit
        if (isdigit(str[i]))
        {
            int operand = 0;
            // * handling more than 1 digit numbers
            while (i < str.length() && isdigit(str[i]))
            {
                operand = (operand * 10) + (str[i] - '0');
                i++;
            }
            i--;
            s.push(operand);
        }
        // ? if its space
        else if (str[i] == ' ' || str[i] == '\t')
        {
            continue;
        }
        // ? if its a operator
        else
        {
            int op1, op2;
            op2 = s.top();
            s.pop();
            op1 = s.top();
            s.pop();

            switch (str[i])
            {
            case '+':
                s.push(op1 + op2);
                break;
            case '-':
                s.push(op1 - op2);
                break;
            case '*':
                s.push(op1 * op2);
                break;
            case '/':
                s.push(op1 / op2);
                break;
            case '%':
                s.push(op1 % op2);
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
    string str = "10 2 * 3 5 * + 9 -";
    cout << mine(str) << endl;
    return 0;
}
