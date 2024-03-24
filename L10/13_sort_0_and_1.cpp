// given an array of 0's and 1's,
//  sort all the zeroes and ones to one side
// eg : {0,1,1,0,0,1} ---> {0,0,0,1,1,1}

#include <iostream>
using namespace std;

void sortArray(int arr[], int size)
{

    // setting two pointers, one at start and one at end:
    int i = 0;
    int j = size - 1;

    // using the two pointer approach:
    while (i < j)
    {
        // checking is i is indexing to 1
        while (arr[i] == 0 && (i < j))
        {
            i++;
        }
        // checking is j is indexing to 0
        while (arr[j] == 1 && (i < j))
        {
            j--;
        }

        // if reached this point, i is indexing to '1' and j is indexing to '0':
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

// function to print the array:
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[8] = {1, 1, 0, 0, 0, 0, 1, 0};

    sortArray(arr, 8);

    printArray(arr, 8);
}