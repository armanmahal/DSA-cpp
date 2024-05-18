// creation of a 2D array in the dynamic/heap memory

#include <iostream>
using namespace std;

int main()
{

    int rows = 3;
    int cols = 4;

    // creating an array of pointers:
    int **arr = new int *[rows];

    // pointing each pointer the above array to an array:
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }

    // taking input:

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }

    // printing output:
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // freeing up/ deallocation of memory:

    // deallocation of each arrays:
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    // deallocation of array of pointers:
    delete[] arr;
}