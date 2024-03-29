// given a 2d array, print its elements by traversing it in a wave form.
/*
    eg : 1|2|3|4
         5|6|7|8
         9|10|11|12  ------> 1,5,9,13,14,10,6,2,3,7,11,15,16,12,8,4
         13|14|15|16
*/

#include <iostream>
using namespace std;

void printWave(int arr[][4], int rows, int columns)
{

    int currentCol = 0;

    while (currentCol < columns)
    {
        // when currentCol is odd, traverse rows from bottom to top:
        //(bitwise and of any number with 1 returns true if the number is odd)
        // eg: (5&1) --> ( (101) & (001) ) --> 1 (true)  ; (6&1) --> ( (110) & (001)) -->  0 (false)
        if (currentCol & 1)
        {

            for (int i = rows - 1; i >= 0; i--)
            {
                cout << arr[i][currentCol] << " ";
            }
        }
        // else when currentCol is even:
        else
        {
            for (int i = 0; i < rows; i++)
            {
                cout << arr[i][currentCol] << " ";
            }
        }
        // incrementing to the next column:
        currentCol++;
    }
    cout << endl;
}// TIME COMPLEXITY : O(m*n) , where n = rows, m = cols

int main()
{
    int arr[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    printWave(arr, 4, 4);
}