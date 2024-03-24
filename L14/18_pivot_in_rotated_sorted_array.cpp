/*

suppose we have a sorted array and we rotate it like this then:
|1| ---> |7|
|2| ---> |8|
|3| ---> |1| <---  THIS IS THE PIVOT ELEMENT
|7| ---> |2|
|9| ---> |3|
 You have to find this pivot element index 'or' the index of least element.

*/

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

int main()
{
    int arr[5] = {7, 8, 1, 2, 3};

    cout << findPivot(arr, 5) << endl;
}