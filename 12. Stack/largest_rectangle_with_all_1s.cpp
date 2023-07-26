#include <bits/stdc++.h>

using namespace std;
const int r = 4;
const int R = 4;
const int c = 4;
const int C = 4;
// This approach has three nested loops, which results in a time complexity of O(R^3 * C^3), making it highly inefficient for larger matrices.
int naive(int arr[R][C])
{
    int maxArea = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (arr[i][j] == 1)
            {
                for (int k = i; k < R; k++)
                {
                    for (int l = j; l < C; l++)
                    {
                        bool flag = true;
                        for (int m = i; m <= k; m++)
                        {
                            for (int n = j; n <= l; n++)
                            {
                                if (arr[m][n] == 0)
                                {
                                    flag = false;
                                }
                            }
                        }
                        if (flag)
                        {
                            int area = (k - i + 1) * (l - j + 1);
                            maxArea = max(maxArea, area);
                        }
                    }
                }
            }
        }
    }
    cout << maxArea << endl;
}

int histogram_area(int arr[], int n)
{
    stack<int> s;
    int tp, curr, res = INT_MIN;
    for (int i = 0; i <= n; i++)
    {
        while (!s.empty() and (i == n or arr[i] <= arr[s.top()]))
        {
            tp = s.top();
            s.pop();
            curr = arr[tp] * (s.empty() ? i : (i - s.top() - 1));
            res = max(res, curr);
        }
        s.push(i);
    }
    return res;
}

int mine(int arr[r][c])
{
    int res = histogram_area(arr[0], c);
    for (int i = 1; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == 1)
            {
                arr[i][j] += arr[i - 1][j];
            }
        }
        res = max(res, histogram_area(arr[i], c));
    }
    return res;
}

int main()
{

    int arr[r][c] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}};
    // int n = sizeof(arr) / sizeof(arr[0]);

    cout << mine(arr);

    return 0;
}
