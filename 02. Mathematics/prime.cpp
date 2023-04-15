#include <iostream>
using namespace std;
int prime(int n)
{
    if (n == 1)
        return false;
    if (n == 2 || n == 3)
        return false;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (i % n == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
int main()
{
    int n = 1031;
    cout << prime(n);
    return 0;
}