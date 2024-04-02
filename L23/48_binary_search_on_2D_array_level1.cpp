// given a matrix(2D array) whose each row is sorted in ascending order and the last element of one row is less than the first element of next row, do binary search on it.
/* example matrix:
    |1 |3 |5 |7 |
    |10|11|16|17|  'or' --> {1,2,5,7,10,11,16,17,23,30,36,60} 
    |23|30|36|60|

    ~thus can apply conventional binary search.
*/
#include <iostream>
using namespace std;

void binary_search(int arr[][4], int key, int rows, int columns)
{
    //finding total number of elements:
    int total = rows * columns;

    //setting two pointers for start and end:
    int start = 0;
    int end = total - 1;

    //calculating mid:
    int mid = start + (end - start) / 2;

    bool found = false;

    while (start <= end)
    {
        //finding the current element that mid refers to:
        int currentRow = mid / columns;
        int currentColumn = mid % columns;
        int currentElement = arr[currentRow][currentColumn];

        //if current element equals key:
        if (currentElement == key)
        {
            cout << "element found at " << currentRow << " , " << currentColumn << endl;
            found = true;
            break;
        }

        //if current element smaller than key, increase start to mid+1:
        else if (currentElement < key)
        {
            start = mid + 1;
        }

        //if current element larger than key, decrease end to mid-1:
        else
        {
            end = mid - 1;
        }

        //recalculating mid:
        mid = start + (end - start) / 2;
    }

    //if not found :
    if (!found)
    {
        cout << "Element does not exist in the array." << endl;
    }
}//TIME COMPLEXITY: O(log(nm)) --> n:rows, m:columns

int main()
{
    int arr[3][4] = {{1, 3, 5, 7},
                     {10, 11, 16, 17},
                     {23, 30, 36, 60}};

    int key = 16;

    binary_search(arr, key, 3, 4);
}