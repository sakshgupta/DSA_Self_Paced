#include <iostream>
using namespace std;

int main()
{
    int arr[] = {3, 8, 12, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 0;
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            int temp = i;
            for (int j = i + 1; j < n; j++)
            {
                arr[temp] = arr[j];
                temp++;
            }
            arr[temp] = 0;
        }
    }
    cout << "\nAfter" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}