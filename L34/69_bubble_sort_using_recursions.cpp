// bubble sort using recursions:
//bubble sort --> placing the current largest element to rightmost position after each iteration.

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

void sortArray(int *arr, int size)
{
    // base case :
    if (size == 1)
    {
        return;
    }

    // placing the largest element to last position
    for (int i = 1; i < size; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            swap(arr[i - 1], arr[i]);
        }
    }

    // recursive call (to sort the remaining array):
    sortArray(arr, size - 1);
}

int main()
{

    int arr[5] = {4, 3, 6, 1, 2};

    sortArray(arr, 5);

    printArray(arr, 5);
}