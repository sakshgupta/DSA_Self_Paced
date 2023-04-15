#include <iostream>
#include <cmath>
using namespace std;

void naive(string s)
{
    int n = s.length();
    int powsize = pow(2, n);
    cout << n << " " << powsize << endl;
    for (int c = 0; c < powsize; c++)
    {
        for (int i = 0; i < n; i++)
        {
            if ((c & (1 << i)) != 0) // this is used to see if the jth+1 bit is set or not (main logic for this pgm)
                cout << s[i];
        }
        cout << endl;
    }
} //Theta(2^n * n)

int main()
{
    string s = "abc";
    naive("abc");
    return 0;
}