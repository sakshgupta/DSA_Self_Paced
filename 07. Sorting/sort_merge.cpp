#include <iostream>
using namespace std;

// void merge(int a[], int low, int mid, int high)
// {
//     int n1 = mid - low + 1, n2 = high - mid;
//     int left[n1], right[n2];
//     for (int i = 0; i < n1; i++)
//     {
//         left[i] = a[low + i];
//     }
//     for (int i = 0; i < n2; i++)
//     {
//         right[i] = a[mid + 1 + i];
//     }

//     int i = 0, j = 0, k = 0;
//     while (i < n1 && j < n2)
//     {
//         if (left[i] <= right[j])
//         {
//             a[k] = left[i];
//             k++;
//             i++;
//         }
//         else
//         {
//             a[k] = right[j];
//             k++;
//             j++;
//         }
//     }
//     while (i < n1)
//     {
//         a[k] = left[i];
//         k++;
//         i++;
//     }
//     while (j < n2)
//     {
//         a[k] = right[j];
//         k++;
//         j++;
//     }
// }

void merge(int array[], int const left, int const mid, int const right)
{
    auto const n1 = mid - left + 1;
    auto const n2 = right - mid;

    // Create temp arrays
    auto *leftArray = new int[n1],
         *rightArray = new int[n2];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < n1; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < n2; j++)
        rightArray[j] = array[mid + 1 + j];

    auto i = 0,   // Initial index of first sub-array
        j = 0;    // Initial index of second sub-array
    int k = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (i < n1)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (j < n2)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int a[], int l, int r)
{
    if (r > l)
    {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    // int arr[] = {-6, -1, -8};
    int a[] = {10, 5, 30, 15, 7};
    int n = sizeof(a) / sizeof(a[0]);
    mergeSort(a, 0, n - 1);
    // efficient(arr, n);
    cout << "\nThe array after function call" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << " ";
    }
}