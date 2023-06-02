#include <bits/stdc++.h>
using namespace std;

void mine(int a1[], int a2[], int m, int n)
{
    unordered_set<int> s(a1, a1 + m);
    int c = 0;

    for (auto i = 0; i < n; i++)
    {
        if (s.count(a2[i]) == 0)
        {
            cout << a2[i] << " ";
            c++;
        }
    }

    for (auto i = 0; i < n; i++)
    {
        if (s.count(a2[i]))
        {
            cout << a2[i] << " ";
            c++;
            s.erase(a2[i]);
        }
    }

    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
        c++;
    }
    cout << endl;
    cout << c << endl;
}

// improved efficient approach
void efficient(int a[], int b[], int m, int n)
{
    unordered_set<int> s(a, a + m);
    for (int i = 0; i < n; i++)
    {
        s.insert(b[i]);
    }
    cout << s.size() << endl;
}

int main()
{
    int a1[] = {15, 20, 5, 15};
    int a2[] = {1, 2, 10};
    int m = sizeof(a1) / sizeof(a1[0]);
    int n = sizeof(a2) / sizeof(a2[0]);
    efficient(a1, a2, m, n);
}