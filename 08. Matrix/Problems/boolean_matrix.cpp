//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to modify the matrix such that if a matrix cell matrix[i][j]
    // is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int>> &arr)
    {
        int r = arr.size();
        int c = arr[0].size();
        bool row[r] = {0};
        bool col[c] = {0};
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (arr[i][j] == 1)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
                cout << row[0] << " hey " << col[0] << endl;
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (row[i] == 1 or col[j] == 1)
                {
                    arr[i][j] = 1;
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> matrix(row);
    for (int i = 0; i < row; i++)
    {
        matrix[i].assign(col, 0);
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }

    Solution ob;
    ob.booleanMatrix(matrix);

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends