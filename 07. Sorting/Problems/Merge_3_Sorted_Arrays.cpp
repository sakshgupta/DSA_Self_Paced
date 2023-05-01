#include <bits/stdc++.h>
using namespace std;

// Effecient
vector<int> mergeThree(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int m, n, o, i, j, k;
    // Get Sizes of three vectors
    m = A.size();
    n = B.size();
    o = C.size();

    // Vector for storing output
    vector<int> D;
    D.reserve(m + n + o);

    i = j = k = 0;

    while (i < m && j < n && k < o)
    {

        // Get minimum of a, b, c
        int m = min(min(A[i], B[j]), C[k]);

        // Put m in D
        D.push_back(m);

        // Increment i, j, k
        if (m == A[i])
            i++;
        else if (m == B[j])
            j++;
        else
            k++;
    }

    // C has exhausted
    while (i < m && j < n)
    {
        if (A[i] <= B[j])
        {
            D.push_back(A[i]);
            i++;
        }
        else
        {
            D.push_back(B[j]);
            j++;
        }
    }

    // B has exhausted
    while (i < m && k < o)
    {
        if (A[i] <= C[k])
        {
            D.push_back(A[i]);
            i++;
        }
        else
        {
            D.push_back(C[k]);
            k++;
        }
    }

    // A has exhausted
    while (j < n && k < o)
    {
        if (B[j] <= C[k])
        {
            D.push_back(B[j]);
            j++;
        }
        else
        {
            D.push_back(C[k]);
            k++;
        }
    }

    // A and B have exhausted
    while (k < o)
        D.push_back(C[k++]);

    // B and C have exhausted
    while (i < m)
        D.push_back(A[i++]);

    // A and C have exhausted
    while (j < n)
        D.push_back(B[j++]);

    return D;
}

// Simpler most optimal
vector<int> merge3sortedoptimal(vector<int> &A, vector<int> &B, vector<int> &C)
{
    vector<int> ans;
    int l1 = A.size();
    int l2 = B.size();
    int l3 = C.size();
    int i = 0, j = 0, k = 0;
    while (i < l1 || j < l2 || k < l3)
    {
        // Assigning a, b, c with max values so that if
        // any value is not present then also we can sort
        // the array.
        int a = INT_MAX, b = INT_MAX, c = INT_MAX;

        // a, b, c variables are assigned only if the
        // value exist in the array.
        if (i < l1)
            a = A[i];
        if (j < l2)
            b = B[j];
        if (k < l3)
            c = C[k];

        // Checking if 'a' is the minimum
        if (a <= b && a <= c)
        {
            ans.push_back(a);
            i++;
        }
        // Checking if 'b' is the minimum
        else if (b <= a && b <= c)
        {
            ans.push_back(b);
            j++;
        }
        // Checking if 'c' is the minimum
        else
        {
            if (c <= a && c <= b)
            {
                ans.push_back(c);
                k++;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> A = {1, 2, 3, 5};
    vector<int> B = {6, 7, 8, 9};
    vector<int> C = {10, 11, 12};

    // Print Result
    vector<int> ans = mergeThree(A, B, C);
    for (auto x : ans)
        cout << x << " ";
    return 0;
}