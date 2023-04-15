#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

string getSum(string n)
{
    int sum = 0;
    for (int i = 0; i < n.length(); i++)
        sum = sum + n[i] - '0';
    return (to_string(sum));
}

int digitalroot(string str)
{
    if (str.length() == 1)
        return str[0] - '0';
    str = getSum(str);
    return digitalroot(str);
}

int main()
{
    string n = "3355";
    cout << typeid(digitalroot(n)).name() << endl;
    return 0;
}