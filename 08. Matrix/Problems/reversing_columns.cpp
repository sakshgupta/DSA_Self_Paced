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
    int r = arr.size();
    int c = arr[0].size();
    for (int i = 0; i < r; i++)
    {
        int low = 0, high = c - 1;
        while (low < high)
        {
            swap(arr[i][low], arr[i][high]);
            low++;
            high--;
        }
    }
}

int main()
{
    int m = 2, n = 5, x = 1;
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
    mine(arr);
    // efficient(arr);
    cout << "After:" << endl;
    print(arr);
}