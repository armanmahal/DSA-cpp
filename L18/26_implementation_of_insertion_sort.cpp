// sort an array with insertion sort
#include <iostream>
using namespace std;

void insertionSort(int arr[], int size)
{
    // for loop to grab each element starting from index-1:
    for (int i = 1; i < size; i++)
    {

        int currentElement = arr[i];

        // loop to compare this currentElement with all previous elements:
        int j = i - 1;
        while (j >= 0)
        {
            // shifting the element to right if it is greater than currentElement:
            if (arr[j] > currentElement)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            // if the element is smaller than or equal to currentElement, no need to compare any further, thus break the loop:
            else
            {
                break;
            }
        }
        // after the loop is complete, j will be indexing to the position where loop stopped, and j+1 will be indexing to the position where the current element should be placed (as all other element would have been shifted to right):
        arr[j+1] = currentElement;
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
    int arr[10] = {56, 3, 76, 8, 2, 47, 2, 37, 0, 7};

    insertionSort(arr, 10);

    printArray(arr, 10);
}