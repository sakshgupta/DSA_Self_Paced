#include <bits/stdc++.h>
using namespace std;

// Effecient
void print(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                cout << arr[i][j] << " ";
            }
        }
        else
        {
            for (int j = arr[i].size() - 1; j >= 0; j--)
            {
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int m = 4, n = 4, x = 1;
    vector<vector<int>> arr;
    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            v.push_back(x++);
        }
        arr.push_back(v);
    }
    print(arr);
}