#include <iostream>
using namespace std;

bool isPalindrome(string &str, int start, int end)
{
    if (start >= end)
        return true;

    return ((str[start] == str[end]) && (isPalindrome(str, start + 1, end - 1)));
}

int main()
{
    string str = "aba";
    int n = str.length();
    cout << isPalindrome(str, 0, n - 1) << endl;
    return 0;
}