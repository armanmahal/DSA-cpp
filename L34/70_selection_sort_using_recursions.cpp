// selection sort using recursions
// selection sort --> placing the current smallest element to leftmost position after each iteration.

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

void sortArray(int *arr, int size, int currentIndex = 0)
{
    // base case:
    if (currentIndex >= size - 1)
    {
        return;
    }

    // placing the smallest element to leftmost position:
    int smallestElementIndex = currentIndex;
    for (int i = currentIndex + 1; i < size; i++)
    {
        if (arr[i] < arr[smallestElementIndex])
        {
            smallestElementIndex = i;
        }
    }
    swap(arr[currentIndex], arr[smallestElementIndex]);

    // recursive call : (to sort the remaining array)
    sortArray(arr, size, ++currentIndex);
}

int main()
{
    int arr[5] = {4, 3, 6, 1, 2};

    sortArray(arr, 5);

    printArray(arr, 5);
}