#include <iostream>
using namespace std;
int main()
{
    int n = 50, a = 0, rev = 0;
    for (int i = n; i > 0; i = i / 10)
    {
        a = i % 10;
        rev = rev * 10 + a;
    }
    if (rev == n)
        printf("%d is palindrome", n);
    else
        printf("%d is not palindrome", n);
    return 0;
}