// The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other.
// APPROACH:
/*
https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/
*/

#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<vector<char>> v)
{
    int N = v.size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// function to check whether given positon is a safe position for the queen to place:
bool isValidPlace(vector<vector<char>> &v, int row, int col)
{
    // checking for a queen in columns:
    for (int i = 0; i < v.size(); i++)
    {
        if (v[row][i] == 'Q')
        {
            return false;
        }
    }
    // checking for queen in rows:
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i][col] == 'Q')
        {
            return false;
        }
    }
    // checking for queen in diagnol:
    int r = row - 1;
    int c = col + 1;
    while (r >= 0 && c < v.size())
    {

        if (v[r][c] == 'Q')
        {
            return false;
        }
        r--;
        c++;
    }
    r = row - 1;
    c = col - 1;
    while (r >= 0 && c >= 0)
    {
        if (v[r][c] == 'Q')
        {
            return false;
        }
        r--;
        c--;
    }
    r = row + 1;
    c = col - 1;
    while (r < v.size() && c >= 0)
    {
        if (v[r][c] == 'Q')
        {
            return false;
        }
        r++;
        c--;
    }
    r = row + 1;
    c = col + 1;
    while (r < v.size() && c < v.size())
    {
        if (v[r][c] == 'Q')
        {
            return false;
        }
        r++;
        c++;
    }

    // if queen not found in any row, col, diag:
    return true;
}

bool solveBoard(vector<vector<char>> &v, int col = 0, int queens = 0)
{
    // base case:
    // if all queens placed, return true:
    if (queens == v.size())
    {
        return true;
    }

    // placing the queen in each row in current column:
    for (int i = 0; i < v.size(); i++)
    {
        // if valid position for queen, place it:
        if (isValidPlace(v, i, col))
        {
            v[i][col] = 'Q';
            // recursive call to check the next column
            if (solveBoard(v, col + 1, queens + 1))
            {
                // if the queens successfuly got placed in the next board:
                return true;
            }
            else
            {
                // else if the queens cannot be placed successfully following this path:
                //  backtracking:
                v[i][col] = 'X';
            }
        }
    }

    // If the queen cannot be placed in any row in
    // this column col  then return false
    return false;
}

int main()
{

    int N = 4;

    // initializing the board:
    vector<vector<char>> board;
    for (int i = 0; i < N; i++)
    {
        vector<char> row;
        for (int j = 0; j < N; j++)
        {
            row.push_back('X');
        }
        board.push_back(row);
    }

    printBoard(board);

    if (solveBoard(board))
    {
        printBoard(board);
    }
    else
    {
        cout << "No solution " << endl;
    }
}