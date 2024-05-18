// creation of a jagged array dynamically (the array in which size of each column may be different)

#include <iostream>
using namespace std;

int main()
{
    // getting number of rows
    int rows = 0;
    cout << "Enter the number of rows: ";
    cin >> rows;

    // creating an array in dynamic memory to store the number of columns in each array:
    int *colSizes = new int[rows];
    // getting number of columns in each array:
    for (int i = 0; i < rows; i++)
    {
        cout << "Enter the Columns in " << i << " row: ";
        cin >> colSizes[i];
    }

    // creating an array of pointers:
    int **arr = new int *[rows];

    // pointing each pointer the above array to an array:
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[colSizes[i]];
    }

    // taking input:
    cout << "Enter the Elements of array: ";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colSizes[i]; j++)
        {
            cin >> arr[i][j];
        }
    }

    // printing output:
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colSizes[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // deallocation of each arrays:
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    // deallocation of array of pointers:
    delete[] arr;

    // deallocation of array of column sizes:
    delete[] colSizes;
}