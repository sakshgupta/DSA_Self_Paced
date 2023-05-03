#include <bits/stdc++.h>
using namespace std;

// Effecient
void mine(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
            if (j == arr[i].size() - 1)
            {
                while (i != arr.size() - 1)
                {
                    i++;
                    cout << arr[i][j] << " ";
                }
                while (j != 0)
                {
                    j--;
                    cout << arr[i][j] << " ";
                }
                while (i != 1)
                {
                    i--;
                    cout << arr[i][j] << " ";
                }
                if (i == 1)
                {
                    return;
                }
            }
        }
    }
}

void efficient(vector<vector<int>> &arr)
{
    int r = arr.size();
    int c = arr[i].size();

    if (r == 1)
    {
        for (int i = 0; i < c; i++)
        {
            cout << mat[0][i] << " ";
        }
    }
    else if (c == 1)
    {
        for (int i = 0; i < r; i++)
        {
            cout << mat[i][0] << " ";
        }
    }
    else
    {
        for (int i = 0; i < c; i++) // First row 
        {
            cout << mat[0][i] << " ";
        }
        for (int i = 1; i < r; i++) // Last Column
        {
            cout << mat[i][c - 1] << " ";
        }
        for (int i = c - 2; i >= 0; i--) // Last Row
        {
            cout << mat[r - 1][i] << " ";
        }
        for (int i = r - 2; i >= 0; i--) // First Column
        {
            cout << mat[i][0] << " ";
        }
    }
}

int main()
{
    int m = 3, n = 2, x = 1;
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
    mine(arr);
}