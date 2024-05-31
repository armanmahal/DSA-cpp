// sorting an array with quick sort:

#include <iostream>
using namespace std;

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int *arr, int start, int end)
{
    // initializing a pivot element:
    int elem = arr[start];

    // finding elements smaller than the pivot element:
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= elem)
        {
            count++;
        }
    }

    // placing the pivot element at its correct position:
    int pivotIndex = start + count;
    if (count != 0)
    {
        swap(arr[start], arr[pivotIndex]);
    }

    // placing all the elements smaller than pivot element to its left side and all the elements larger than pivot element to its right side:
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        // finding any larger element on left side:
        while (arr[i] <= elem)
        {
            i++;
        }
        // finding any smaller element on right side:
        while (arr[j] >= elem)
        {
            j--;
        }

        // swapping the foul elements:
        if (j > pivotIndex && i < pivotIndex)
        {
            swap(arr[j], arr[i]);
        }
    }

    // returning the position of pivot element:
    return pivotIndex;
}

void quickSort(int *arr, int start, int end)
{
    // base case:
    if (start >= end)
    {
        return;
    }

    // doing partition of the array:
    int pivot = partition(arr, start, end);
    ;

    // recursive call to quick sort left part of pivot:
    quickSort(arr, start, pivot - 1);
    // recursive call to quick sort right part of pivot:
    quickSort(arr, pivot + 1, end);
}

int main()
{
    int size = 8;
    int arr[size] = {5, 4, 3, 6, 1, 2, 10, 7};

    int size2 = 9;
    int arr2[size2] = {100, 3, 2, 65, 6, 3, 2, 1, 0};

    quickSort(arr, 0, size - 1);
    quickSort(arr2, 0, size2 - 1);

    printArray(arr, 8);
    printArray(arr2, 9);
}