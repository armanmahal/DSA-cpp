// sort a given array with bubble sort
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size)
{
    //traversal of swapping will happen for size-1 times
    for (int i = 1; i < size ; i++)
    {

        int j = 0;
        bool ifSwapped = false;

        while (j < (size - i))
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                ifSwapped = true;
            }
            j++;
        }
        //if no swaps happen, it means array is already sort, then just break the loop:
        if (ifSwapped == false)
        {
            break;
        }
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

    int arr[10] = {3, 23, 564, 12, 8, 23, 4, 1, 0, 12};

    bubbleSort(arr, 10);

    printArray(arr, 10);
}