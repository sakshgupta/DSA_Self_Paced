#include <bits/stdc++.h>
using namespace std;

void mine(int arr[], int n, int k)
{
    int hash[k];
    for (int i = 0; i < k; i++)
    {
        hash[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int index = arr[i] % k;
        if (hash[index] == -1)
        {
            hash[index] = arr[i];
        }
        else
        {
            for (int j = 0; j < k; j++)
            {
                // Computing the new hash value
                int t = (index + j * j) % k;
                if (hash[t] == -1)
                {
                    // Break the loop after
                    // inserting the value
                    // in the hash
                    hash[t] = arr[i];
                    break;
                }
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        cout << hash[i] << " ";
    }
}

// improved efficient approach
void efficient(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for (auto e : m)
    {
        if (e.second > n / k)
        {
            cout << e.first << " ";
        }
    }
}

int main()
{
    int a1[] = {21, 10, 32, 43};
    int n = sizeof(a1) / sizeof(a1[0]);
    mine(a1, n, 11);
}