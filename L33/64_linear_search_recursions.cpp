// linear search using recursions

#include <iostream>
using namespace std;

bool findElement(int arr[], int size, int key)
{
    // base case:
    if (size == 0)
    {
        return false;
    }

    // if found:
    if (arr[0] == key)
    {
        return true;
    }

    else
    {
        return findElement(arr + 1, size - 1, key);
    }
}

int main()
{
    int arr[6] = {1, 2, 3, 6, 7, 9};
    int key1 = 6;
    int arr2[5] = {1, 2, 3, 6, 4};
    int key2 = 10;

    cout << findElement(arr, 6, key1) << endl;
    cout << findElement(arr2, 5, key2) << endl;
}