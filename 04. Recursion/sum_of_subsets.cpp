#include <iostream>
using namespace std;

int subsets(int a[10], int sum, int i)
{
    if (i == 0)
        return (sum == 0) ? 1 : 0;

    return subsets(a, sum, i - 1) || subsets(a, sum - a[i - 1], i - 1); 
}

int main()
{
    int arr[10] = {10, 20, 15};
    int sum = 25;
    int n = sizeof(arr) / sizeof(arr[0]);
    if (subsets(arr, sum, n) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    return 0;
}