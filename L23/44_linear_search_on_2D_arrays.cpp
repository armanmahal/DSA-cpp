// given a 2D array find if an element exists or not using linear search

#include <iostream>
#include <string>
using namespace std;

bool linearSearch(int arr[][5] /*it is important to write the number of columns while passing the 2D arrays into a function*/, int rows, int columns, int key)
{

    // traversing the whole 2d array:
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (arr[i][j] == key)
            {
                return 1;
            }
        }
    } // TIME COMPLEXITY ---> O(n*m) where n = no of rows, m = no of columns
    return 0;
}

int main()
{
    int arr[3][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    int key = 15;

    string ans = linearSearch(arr, 3, 5, key) ? "found" : "not found";

    cout << ans << endl;
}