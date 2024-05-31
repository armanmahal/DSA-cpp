// implementation of merge sort , done with recursions

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

void merge(int *arr, int start, int end)
{
    // finding the mid:
    int mid = start + (end - start) / 2;

    // creating two arrays dynamically to represent the two sorted halves of original array:
    int length1 = mid - start + 1;
    int *arr1 = new int[length1];
    int length2 = end - mid;
    int *arr2 = new int[length2];

    // copying the elements into the arrays:
    int mainArrayIndex = 0;
    for (int i = 0; i < length1; i++)
    {
        arr1[i] = arr[mainArrayIndex];
        mainArrayIndex++;
    }
    for (int i = 0; i < length2; i++)
    {
        arr2[i] = arr[mainArrayIndex];
        mainArrayIndex++;
    }

    // merging the two array:
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = 0;
    while (index1 < length1 && index2 < length2)
    {
        if (arr1[index1] < arr2[index2])
        {
            arr[mainArrayIndex] = arr1[index1];
            mainArrayIndex++;
            index1++;
        }
        else
        {
            arr[mainArrayIndex] = arr2[index2];
            mainArrayIndex++;
            index2++;
        }
    }
    while (index1 < length1)
    {
        arr[mainArrayIndex++] = arr1[index1++];
    }
    while (index2 < length2)
    {
        arr[mainArrayIndex++] = arr2[index2++];
    }

    // freeing up the dynamically allcated arrays:
    delete[] arr1;
    delete[] arr2;
}

void mergeSort(int *arr, int start, int end)
{
    // base case:
    if (start >= end)
    {
        return;
    }

    // finding the mid:
    int mid = start + (end - start) / 2;

    // recursive call to sorting the left half:
    mergeSort(arr, start, mid);
    // recursive call to sorting the right half:
    mergeSort(arr, mid + 1, end);

    // merging the two sorted halves:
    merge(arr, start, end);
}

int main()
{
    int size = 5;
    int arr[size] = {4, 3, 6, 1, 2};

    mergeSort(arr, 0, size - 1);

    printArray(arr, 5);
}