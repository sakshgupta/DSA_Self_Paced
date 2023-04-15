#include <iostream>
using namespace std;

int main()
{
    int n = 7;
    int res = 0;
    while (n > 0)
    {
        if (n & 1 == 1)
            res++;
        n = n >> 1;
    }
    cout << res << endl;
    return 0;
}