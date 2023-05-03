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
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    cout << "After transpose:" << endl;
    print(arr);
    for (int i = 0; i < n; i++)
    {
        int low = 0, high = n - 1;
        while (low < high)
        {
            swap(arr[low][i], arr[high][i]); // column wise swapping
            low++;
            high--;
        }
    }
}


int main()
{
    int m = 3, n = 3, x = 1;
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