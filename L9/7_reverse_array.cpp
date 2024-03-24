// Reversing a given Array

#include <iostream>
using namespace std;

// functio to reverse the array
void reverseArray(int arr[], int size)
{
    // initializing varibles:
    int start = 0;
    int end = size - 1;
    int temp;

    // condition:
    while (start < end)
    {

        // swapping:

        /*
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        */

        swap(arr[start], arr[end]);

        // increment and decrement to start and end pointers
        start++;
        end--;
    }
}

// function to print the array:
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

    int evenArr[4] = {1, 2, 3, 4};
    int oddArr[5] = {1, -2, 3, 4, 0};
    int singleArr[1] = {1};

    reverseArray(evenArr, 4);
    reverseArray(oddArr, 5);
    reverseArray(singleArr, 1);

    printArray(evenArr, 4);
    printArray(oddArr, 5);
    printArray(singleArr, 1);
}