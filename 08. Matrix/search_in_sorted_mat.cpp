#include <bits/stdc++.h>
using namespace std;

// Effecient
void print(int arr[4][4], int x)
{
    int r = 4;
    int c = 4;
    for (int i = 0; i < r; i++)
    {
        int low = 0, high = c - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[i][mid] == x)
            {
                cout << i << " " << mid << endl;
                return;
            }
            else if (arr[i][mid] > x)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    cout << "Not Found" << endl;
}

void efficient(int arr[4][4], int x)
{
    int i = 0, j = 3;
    while (i <= 3 and j >= 0)
    {
        if (arr[i][j] == x)
        {
            cout << i << " " << j << endl;
            return;
        }
        else if (arr[i][j] > x)
        {
            j--;
        }
        else
            i++;
    }
    cout << "noot found" << endl;
}

int main()
{
    int arr[4][4] = {{10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 50}};

    efficient(arr, 29);
}