#include <iostream>
using namespace std;
int main()
{
    int n = 10, p = 1, c = 0;
    for (int i = 1; i <= n; i++)
    {
        p = p * i;
    }
    for (int i = p; i > 0; i /= 10)
    {
        int a = i % 10;
        if (a == 0)
        {
            c++;
        }
        else
            break;
    }
    printf("Number of trailing zeros in the factorial are: %d", c);
    return 0;
}