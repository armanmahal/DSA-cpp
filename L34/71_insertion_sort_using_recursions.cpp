// insertion sort using recursions
// insertion sort( LECTURE - 18 ):- sorting the array step by step 'or' sorting done by placing the correct element to its correct position (in smaller arrays) after each iteraion

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

void sortArray(int *arr, int size, int currentIndex = 1)
{
    // base case:
    if (currentIndex >= size)
    {
        return;
    }

    // placing the correct element to its correct position:
    int indexToBePlacedAt = currentIndex;
    int currentElement = arr[currentIndex];
    for (int i = currentIndex; i > 0; i--)
    {
        if (currentElement < arr[i - 1])
        {
            // then shift the element to right
            arr[i] = arr[i - 1];
            indexToBePlacedAt = i - 1;
        }
        else
        {
            break; // because we know the rest of the array is sorted, we just need to insert this current element to its correct position in the array.
        }
    }
    arr[indexToBePlacedAt] = currentElement; // placing the correct element to correct position

    // recursive call: (to sort a bigger array)
    sortArray(arr, size, currentIndex + 1);
}

int main()
{
    int arr[5] = {4, 3, 6, 1, 2};

    sortArray(arr, 5);

    printArray(arr, 5);
}