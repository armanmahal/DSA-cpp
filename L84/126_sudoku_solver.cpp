// solving sudoku using backtracking:

/*
Given a partially filled 9×9 2D array ‘grid[9][9]’, the goal is to assign digits (from 1 to 9) to the empty cells so that every row, column, and subgrid of size 3×3 contains exactly one instance of the digits from 1 to 9.
Empty cells are represented by 0.
*/

/*

Examples:

Input: grid
{ {3, 0, 6, 5, 0, 8, 4, 0, 0},
{5, 2, 0, 0, 0, 0, 0, 0, 0},
{0, 8, 7, 0, 0, 0, 0, 3, 1},
{0, 0, 3, 0, 1, 0, 0, 8, 0},
{9, 0, 0, 8, 6, 3, 0, 0, 5},
{0, 5, 0, 0, 9, 0, 6, 0, 0},
{1, 3, 0, 0, 0, 0, 2, 5, 0},
{0, 0, 0, 0, 0, 0, 0, 7, 4},
{0, 0, 5, 2, 0, 6, 3, 0, 0} }
Output:
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9

*/

#include <iostream>
#include <vector>
using namespace std;

void printSudoku(vector<vector<int>> v)
{
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

bool isValid(vector<vector<int>> v, int row, int col, int value)
{
    for (int i = 0; i < v.size(); i++)
    {
        // checking row:
        if (v[row][i] == value)
        {
            return false;
        }
        // chekcing column:
        if (v[i][col] == value)
        {
            return false;
        }
        // checking 3x3 corresponding subgrid:
        int startingCol = (col / 3) * 3;
        int startingRow = (row / 3) * 3;
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                if (v[startingRow + x][startingCol + y] == value)
                {
                    return false;
                }
            }
        }
    }

    // if not found:
    return true;
}

bool solveSudoku(vector<vector<int>> &v)
{
    // iterating over each element of board:
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            // if current element if empty (0):
            if (v[i][j] == 0)
            {
                // try putting each value to this position:
                for (int val = 1; val <= 9; val++)
                {
                    if (isValid(v, i, j, val))
                    {
                        // if this value is valid to insert at this position
                        v[i][j] = val;

                        // recursive call to check next solution possible or not with value at this position:
                        if (solveSudoku(v))
                        {
                            return true;
                        }
                        // if solution not possible with this value at this position:
                        else
                        {
                            // then do backtracking:
                            // i.e remove this value from this position.
                            v[i][j] = 0;
                        }
                    }
                }
                // if no solution is found with any value:
                return false; // no solution is possible then
            }
        }
    }

    // if solved:
    return true;
}

int main()
{
    vector<vector<int>> board = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                                 {5, 2, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 8, 7, 0, 0, 0, 0, 3, 1},
                                 {0, 0, 3, 0, 1, 0, 0, 8, 0},
                                 {9, 0, 0, 8, 6, 3, 0, 0, 5},
                                 {0, 5, 0, 0, 9, 0, 6, 0, 0},
                                 {1, 3, 0, 0, 0, 0, 2, 5, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 7, 4},
                                 {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    printSudoku(board);

    if (solveSudoku(board))
    {
        printSudoku(board);
    }
    else
    {
        cout << "No Solution" << endl;
    }
}
