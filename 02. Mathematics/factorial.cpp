#include <iostream>
using namespace std;
// Recursive Method
int fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

// Iterative Method
int main()
{
    int n = 4, p = 1;
    // for (int i = 1; i <= n; i++){
    //     p=p*i;
    // }
    cout << "The factorial is " << fact(n);
    return 0;
}
