//  rat in a maze problem, given a matrix or 2d array
//  the rat is at index (0,0)
//  and it has to go at (n-1,n-1) ,
//  n is the number of rows and columns in the given 2d array
//  the given 2d array has either 0 or 1
//  the rat can follow the path where there is 1
//  but it cannot go to the path where there is 0
//  give all the possible ways that rat can reach its destination in the matrix
//  the rat can move either Down, Up, Left, Right
//  store each of successive move in a string as D,U,L,R
//  give the array containing all the strings of possible paths

#include <iostream>
#include <vector>
using namespace std;

void printStringVector(vector<string> vec)
{
    cout << "[ ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << "  ";
    }
    cout << "]" << endl;
}

bool isValidPath(vector<vector<int>> &maze, int size, vector<vector<int>> &visited, int srcx, int srcy)
{
    // checking the conditions for the path to be valid:
    if (
        // the path should be within the bounds:
        (srcy < size && srcy >= 0) &&
        (srcx < size && srcx >= 0) &&
        // the path in maze should be 1:
        maze[srcx][srcy] == 1 &&
        // the path should already no be visited:
        visited[srcx][srcy] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(vector<vector<int>> &maze, int size, vector<vector<int>> &visited, vector<string> &ans, string &currentPath, int srcx = 0, int srcy = 0)
{
    // basecase:
    // if the rat reaches the destination:
    if (srcx == size - 1 && srcy == size - 1)
    {
        ans.push_back(currentPath);
        return;
    }

    // marking the current coordinated in visited as 1:
    visited[srcx][srcy] = 1;

    // move down after checking if moving down is a valid path:
    if (isValidPath(maze, size, visited, srcx + 1, srcy))
    {
        currentPath.push_back('D');

        // recursive call after moving down:
        solve(maze, size, visited, ans, currentPath, srcx + 1, srcy);
        // backtracking: to remove the last added path:
        currentPath.pop_back();
    }

    // move up after checking if moving up is a valid path:
    if (isValidPath(maze, size, visited, srcx - 1, srcy))
    {
        currentPath.push_back('U');

        // recursive call after moving up:
        solve(maze, size, visited, ans, currentPath, srcx - 1, srcy);
        // backtracking: to remove the last added path:
        currentPath.pop_back();
        ;
    }

    // move right after checking if moving right is a valid path:
    if (isValidPath(maze, size, visited, srcx, srcy + 1))
    {
        currentPath.push_back('R');

        // recursive call after moving right:
        solve(maze, size, visited, ans, currentPath, srcx, srcy + 1);
        // backtracking: to remove the last added path:
        currentPath.pop_back();
    }

    // move left after checking if moving left is a valid path:
    if (isValidPath(maze, size, visited, srcx, srcy - 1))
    {
        currentPath.push_back('L');

        // recursive call after moving left:
        solve(maze, size, visited, ans, currentPath, srcx, srcy - 1);
        // backtracking: to remove the last added path:
        currentPath.pop_back();
    }

    // backtracking: marking the current coordinated as not visited:
    visited[srcx][srcy] = 0;
}

int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};
    // numbers of rows or columns in maze:
    int size = maze.size();
    // vector to store all the valid paths
    vector<string> ans;
    // Store current path
    string currentPath = "";

    // vector to mark the path that the rat has already visited, so as to prevent an infinite loop
    vector<vector<int>> visited = maze;
    // initialize it with 0, and mark the coordinates that rat has visited with 1:
    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[0].size(); j++)
        {
            visited[i][j] = 0;
        }
    }

    if (maze[0][0] == 1)
    {
        visited[0][0] = 1;
        solve(maze, size, visited, ans, currentPath);
    }
    else
    {
        cout << "no solution" << endl;
    }

    printStringVector(ans);
}
