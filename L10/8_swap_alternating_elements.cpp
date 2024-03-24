// swap the alternating elements of an array
//      1,2,3,4       --->    2,1,4,3
//      1,2,3,4,5,6,7 --->    2,1,4,3,6,5,7

#include <iostream>
using namespace std;

void swapAlternative(int arr[], int size)
{
    for (int i = 0; i < size - 1; i += 2)
    {
        swap(arr[i], arr[i + 1]);
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
    int array1[1] = {0};
    int array2[2] = {0, 2};
    int array3[4] = {0, 2, 1, 2};
    int array4[5] = {0, 2, 3, 4, 5};

    swapAlternative(array1, 1);
    swapAlternative(array2, 2);
    swapAlternative(array3, 4);
    swapAlternative(array4, 5);

    printArray(array1, 1);
    printArray(array2, 2);
    printArray(array3, 4);
    printArray(array4, 5);
}