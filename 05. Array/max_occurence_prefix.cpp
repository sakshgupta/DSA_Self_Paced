// C++ program to find maximum occurred element in
// given N ranges.
#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int maximumOccurredElement(int L[], int R[], int n)
{
    int arr[MAX];
    cout << "Yo;";
    memset(arr, 0, sizeof arr);

    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        arr[L[i]] += 1;
        arr[R[i] + 1] -= 1;
        if (R[i] > maxi)
        {
            maxi = R[i];
        }
    }

    int msum = arr[0], ind;
    for (int i = 1; i < maxi + 1; i++)
    {
        arr[i] += arr[i - 1];
        if (msum < arr[i])
        {
            msum = arr[i];
            ind = i;
        }
    }

    return ind;
}

// Driven code
int main()
{
    int L[] = {1, 4, 9, 13, 21};
    int R[] = {15, 8, 12, 20, 30};
    int n = sizeof(L) / sizeof(L[0]);

    cout << maximumOccurredElement(L, R, n) << endl;
    return 0;
}
