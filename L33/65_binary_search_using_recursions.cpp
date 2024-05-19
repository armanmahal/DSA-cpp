// binary search using recursions

#include <iostream>
using namespace std;

bool findElement(int arr[], int start, int end, int key)
{
    // base cases:
    // if not found
    if (start > end)
    {
        return false;
    }

    // calculating mid:
    int mid = start + end - start / 2;

    // if found:
    if (arr[mid] == key)
    {
        return true;
    }

    else if (arr[mid] < key)
    {
        return findElement(arr, mid + 1, end, key);
    }
    else
    {
        return findElement(arr, start, mid - 1, key);
    }
}

int main()
{
    int arr[6] = {1, 2, 3, 6, 7, 9};
    int key1 = 6;
    int arr2[5] = {1, 2, 3, 6, 4};
    int key2 = 10;

    cout << findElement(arr, 0, 5, key1) << endl;
    cout << findElement(arr2, 0, 4, key2) << endl;
}