#include <iostream>
using namespace std;
void printdivisors(int n)
{
    int i;
    for (i = 1; i * i < n; i++)
    {
        if (n % i == 0)
            cout << i << " ";
    }
    for (; i > 0; i--)
    {
        if (n % i == 0)
            cout << n / i << "";
    }
}
int main()
{
    int n = 450;
    printdivisors(n);
    return 0;
}