#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n = 15;
    vector<bool> isPrime(n + 1, true);

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            cout << i << " ";
            for (int j = i * i; j <= n; j = j + i)
                isPrime[j] = false;
        }
    }
}