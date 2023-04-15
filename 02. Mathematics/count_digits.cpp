#include <iostream>
using namespace std;
int main()
{
    int n = 10000;
    int c = 0;
    for (int i = n; i > 0; i = i / 10)
    {
        c++;
    }
    cout << c << endl;
    return 0;
}