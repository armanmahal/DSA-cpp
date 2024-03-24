// given a sorted and then rotated array, find a given element from the array

#include <iostream>
using namespace std;

int findPivot(int arr[], int size)
{
    // initialising two pointers for start and end:
    int s = 0;
    int e = size - 1;
    // initialising the mid:
    int mid = s + (e - s) / 2;

    // condition:
    while (s < e)
    {
        // if mid is in first increasing part of array:
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        // else mid is in second increasing part of array 'or'
        // mid IS THE PIVOT:
        else
        {
            e = mid;
        }
        // updating mid:
        mid = s + (e - s) / 2;
    }

    // after the loop is complete , e and s shall be pointing to pivot, thus:
    return e;
}

int binarySearch(int arr[], int key, int startIndex, int endIndex)
{

    // initializing start and end pointers:
    int s = startIndex;
    int e = endIndex;

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
    int arr[5] = {12, 15, 18, 2, 4};
    int key = 12;

    // getting the pivot index of the array:
    int pivot = findPivot(arr, 5);

    int answerIndex = -1;

    // if the key is greater than or equal to arr[0], then search in part I of array
    // i.e: the part before the pivot point:
    if (key >= arr[0])
    {
        answerIndex = binarySearch(arr, key, 0, pivot - 1);
    }
    // else search for the key in part II of array
    // i.e: the part including and after pivot point:
    else
    {
        answerIndex = binarySearch(arr, key, pivot, 5);
    }

    cout << "the index of key is : " << answerIndex << endl;
}