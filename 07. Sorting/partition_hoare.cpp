#include <iostream>
using namespace std;

int mine(int arr[], int l, int h)
{
    int p = arr[l];
    int i = l - 1, j = h + 1;
    while (true)
    {
        // Find leftmost larger element than pivot
        do
        {
            i++;
        } while (arr[i] < p);

        // Find rightmost smaller element than pivot
        do
        {
            j--;
        } while (arr[j] > p);

        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int a[] = {5, 3, 8, 4, 2, 7, 1, 10};
    int n = sizeof(a) / sizeof(a[0]);
    cout << mine(a, 0, n - 1);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << " ";
    }
}