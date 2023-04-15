#include <iostream>
using namespace std;

int sumofn(int n)
{
    if (n == 0)
        return 0;
    return n + sumofn(n - 1);
}

int main()
{
    int n = 5;
    cout << sumofn(n) << endl;
    return 0;
}