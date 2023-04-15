// CPP program to generate power set
#include <bits/stdc++.h>
using namespace std;

long long sum = 0;
int onegoodnumber(int n, int D)
{
    sum = sum + n % 10;
    n = n / 10;
    while (n > 0)
    {
        if (n % 10 < sum)
            return 0;
        if (n % 10 == D)
            return 0;
        n = n / 10;
    }
    return 1;
}

int main()
{
    cout << onegoodnumber(200, 4);
    return 0;
}
