// Binary search Algorithm

#include <iostream>
using namespace std;

int binarySearch(int arr[], int key, int size)
{

    // initializing start and end pointers:
    int s = 0;
    int e = size - 1;

    int mid = s + (e - s) / 2; // mid can be found by:(e+s)/2 ,but this is more optimized

    // writing the condition:
    while (s <= e)
    {
        // if key found:
        if (arr[mid] == key)
        {
            return mid;
        }
        // if key greater than current element:
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        // if key less than current element:
        else
        {
            e = mid - 1;
        }
        // reevaluating the mid:
        mid = s + (e - s) / 2;
    }

    // return -1 if not found:
    return -1;
}

int main()
{

    int oddArray[5] = {2, 5, 7, 9, 12};
    int evenArray[8] = {1, 4, 6, 7, 9, 13, 15, 21};

    int key = 9;

    cout << binarySearch(oddArray, key, 5) << endl;
    cout << binarySearch(evenArray, key, 8) << endl;
}