// given a sorted array,
// find the number of occurences of an element.
#include <iostream>
using namespace std;

int firstOccurence(int arr[], int size, int key)
{
    // initializing start and end pointers:
    int s = 0;
    int e = size - 1;

    int mid = s + (e - s) / 2; // mid can be found by:(e+s)/2 ,but this is more optimized

    int ans = -1;
    // writing the condition:
    while (s <= e)
    {
        // if key found:
        if (arr[mid] == key)
        {
            ans = mid;
            // search in lower half to get the first occurence:
            e = mid - 1;
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

    return ans;
}

int lastOccurence(int arr[], int size, int key)
{
    // initializing start and end pointers:
    int s = 0;
    int e = size - 1;

    int mid = s + (e - s) / 2; // mid can be found by:(e+s)/2 ,but this is more optimized

    int ans = -1;
    // writing the condition:
    while (s <= e)
    {
        // if key found:
        if (arr[mid] == key)
        {
            ans = mid;
            // search in upper half to get the last occurence:
            s = mid + 1;
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

    return ans;
}

int main()
{
    int arr[6] = {1, 2, 3, 3, 3, 5};
    int key = 3;

    int first = firstOccurence(arr,6,key);
    int last = lastOccurence(arr,6,key);

    cout<<"the Number of occurences is: "<< (last-first)+1 <<endl;
}