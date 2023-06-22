#include <bits/stdc++.h>
using namespace std;

bool mine(string &str)
{
    int low = 0, high = str.length() - 1;
    while (low < high)
    {
        if (str[low] != str[high])
            return false;
        low++;
        high--;
    }
    return true;
}

// improved efficient approach
void change(int arr[], int n)
{
    unordered_set<int> s(arr, arr + n);
    cout << s.size() << endl;
}

int main()
{
    string str = "abcdcba";
    cout << mine(str);
}