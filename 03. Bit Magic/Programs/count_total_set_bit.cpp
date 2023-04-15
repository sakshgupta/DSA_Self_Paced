#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largesttwopower(int n)
    {
        int x = 0;
        while ((1 << x) <= n)
            x++;
        return x - 1;
    }
    int countSetBits(int n)
    {
        if (n == 0)
            return 0;
        int x = largesttwopower(n);
        int bitupto2raisex = x * (1 << (x - 1)); //x * 2^(x-1)
        int msbfrom2raisexton = n - (1 << x) + 1; //n - 2^x + 1
        int rest = n - (1 << x); //n - 2^x
        int answer = bitupto2raisex + msbfrom2raisexton + countSetBits(rest);
        return answer;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution ob;
    cout << ob.countSetBits(n) << endl;
    return 0;
}