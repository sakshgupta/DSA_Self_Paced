#include <iostream>
using namespace std;

int main()
{
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 0;
    cout << "Array before insertion is:";
    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Enter the no." << endl;
    cin >> x;

    arr[n] = x;
    cout << "Array before insertion is:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}