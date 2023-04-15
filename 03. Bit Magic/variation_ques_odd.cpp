// Given an array of n number that has values in range 1 to n+1. Every num apperars exactly once. Hence one number is missing. Find the missing number.
#include <iostream>
using namespace std;

void mine(int a[], int n)
{
    int xr = 0;
    int temp = 0;
    // calculate xor of all the elements of the array
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ a[i];
    }
    // calculate xor of all numbers from 1 to n+1
    for (int j = 1; j <= n + 1; j++)
    {
        temp = temp ^ j;
    }
    // if we xor the xor of all the elements of the array and all the numbers from 1 to n+1 then then the duplicate values will cancel each other and the result will be the missing element
    cout << (xr ^ temp) << endl;
}

int main()
{
    int a[] = {1, 6, 3, 4, 2};
    int n = sizeof(a) / sizeof(a[0]);
    mine(a, n);
    return 0;
}