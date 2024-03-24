// sort a given array with selection sort

#include <iostream>
using namespace std;

void selectionSort(int arr[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        int smallestElementIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[smallestElementIndex])
            {
                smallestElementIndex = j;
            }
        }
        swap(arr[i], arr[smallestElementIndex]);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[10] = {3, 7, 12, 4, 324, 7, 34, 1, 8, 0};

    printArray(arr, 10);

    selectionSort(arr, 10);

    printArray(arr, 10);
}