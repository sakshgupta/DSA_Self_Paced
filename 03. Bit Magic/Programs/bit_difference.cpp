#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countBitsFlip(int a, int b)
    {
        int i = 0;
        while (a || b)
        {
            if (a % 2 != b % 2)
                i++;
            a = a / 2;
            b = b / 2;
        }
        return i;
    }
};

int main()
{
    int a, b;
    cin >> a >> b;

    Solution ob;
    cout << ob.countBitsFlip(a, b) << endl;
    return 0;
}