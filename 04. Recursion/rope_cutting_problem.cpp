#include <iostream>
#include <algorithm>
using namespace std;

int rope_pieces(int n, int a, int b, int c)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;
    int res = max({rope_pieces(n - a, a, b, c), rope_pieces(n - b, a, b, c), rope_pieces(n - c, a, b, c)});

    if (res == -1)
        return -1;
    return res + 1;
}

int main()
{
    int n = 9;
    int a = 2;
    int b = 2;
    int c = 2;
    cout << rope_pieces(n, a, b, c) << endl;
    return 0;
}