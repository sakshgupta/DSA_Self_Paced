#include <iostream>
using namespace std;

int digits(int n)
{
    if (n == 0)
        return 0;
    return 1 + digits(n / 10);
}

int main()
{
    int n = 2553643;
    cout << digits(n) << endl;
    return 0;
}