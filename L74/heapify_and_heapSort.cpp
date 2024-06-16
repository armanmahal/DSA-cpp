// heapify algorithm: placing the given element to its correct position according to a heap,
// heapSort: given an heap in array form, sort that array in ascending order.

#include <iostream>
using namespace std;

// HEAPIFY ALGORITHM:
//  function to place the given index element to its correct position in the heap:
void heapify(int *arr, int size, int rootNodeIndex)
{
    // indexes of root node children:
    int left = 2 * rootNodeIndex;
    int right = 2 * rootNodeIndex + 1;

    // if left child is larger than the current node element:
    if (left <= size && arr[rootNodeIndex] < arr[left])
    {
        swap(arr[rootNodeIndex], arr[left]);
        // recursive call to check it with its new index:
        heapify(arr, size, left);
    }
    // if right child is larger than the current node element:
    if (right <= size && arr[rootNodeIndex] < arr[right])
    {
        swap(arr[rootNodeIndex], arr[right]);
        // recursive call to check it with its new index:
        heapify(arr, size, right);
    }
}

// HEAPSORT :
void heapSort(int *arr, int size)
{

    while (size > 1)
    {
        // swap the root node(largest element) with last element:
        swap(arr[size], arr[1]);

        cout << endl;
        // now the largest elemnet is at its correct position.
        size--;

        // place the new root element to its correct position in the heap:
        heapify(arr, size, 1);
    }
}

int main()
{
    int size = 6;
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // converting the given array to heap form:
    // placing its each element to correct positon using the heapify function, the loop should only be run from size/2 to 1 index because the indexes from size/2+1 to n are leaf nodes which we donot need to include to heapify because they are leaf nodes and they got no child to compare them to:
    for (int i = size / 2; i > 0; i--)
    {
        heapify(arr, size - 1, i);
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // sorting the given array of heap:
    heapSort(arr, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}