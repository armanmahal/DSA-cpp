// check if an array is sorted or not using recursions

#include <iostream>
using namespace std;

bool isSorted(int arr[], int size)
{
    // base case:
    // if array of one size then sorted
    if (size == 0 || size == 1)
    {
        return true;
    }

    // condition if next element is smaller than previous:
    if (arr[0] > arr[1])
    {
        return false;
    }

    // recursive call:
    // increase the first index of array and decrease its size:
    return isSorted(arr + 1, size - 1);
}

int main()
{
    int arr[6] = {1, 2, 3, 6, 7, 9};
    int arr2[5] = {1, 2, 3, 6, 4};

    cout << isSorted(arr, 6) << endl;
    cout << isSorted(arr2, 5) << endl;
}