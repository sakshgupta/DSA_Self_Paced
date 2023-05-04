#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void mine(vector<vector<int>> &arr)
{
    vector<vector<int>> temp;
    for (int i = 0; i < arr.size(); i++)
    {
        vector<int> v;
        for (int j = 0; j < arr[i].size(); j++)
        {
            v.push_back(arr[j][i]);
        }
        temp.push_back(v);
        v.clear();
    }
    arr.clear();
    for (int i = 0; i < temp.size(); i++)
    {
        vector<int> v;
        for (int j = 0; j < temp[i].size(); j++)
        {
            v.push_back(temp[i][j]);
        }
        arr.push_back(v);
        v.clear();
    }
}

void efficient(vector<vector<int>> &arr)
{
    int temp = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr[i].size(); j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
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
    cout << "Before:" << endl;
    print(arr);
    // mine(arr);
    efficient(arr);
    cout << "After:" << endl;
    print(arr);
}