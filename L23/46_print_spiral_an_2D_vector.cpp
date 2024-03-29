// given an 2d vector (array) , print its elements in spiral form
/*
    eg : 1|2|3|4
         5|6|7|8
         9|10|11|12  ------> 1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10
         13|14|15|16
*/
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

vector<int> spiralPrint(vector<vector<int>> vec)
{

    // finding the number of rows and columns in the 2D vector:
    int rows = vec.size();
    int cols = vec[0].size();
    // finding total elements in the matrix:
    int total = rows * cols;

    int startingRow = 0;
    int startingCol = 0;
    int endingCol = cols - 1;
    int endingRow = rows - 1;

    // setting a counter to keep track of elements traversed:
    int count = 0;

    vector<int> answer;

    while (count < total)
    {
        // printing the starting row and then incrementing it :
        for (int currentCol = startingCol; (currentCol <= endingCol) && (count < total); currentCol++)
        {
            answer.push_back(vec[startingRow][currentCol]);
            count++;
        }
        startingRow++;

        // printing the ending column and then decrementing it :
        for (int currentRow = startingRow; (currentRow <= endingRow) && (count < total); currentRow++)
        {
            answer.push_back(vec[currentRow][endingCol]);
            count++;
        }
        endingCol--;

        // printing the ending row and then decrementing it :
        for (int currentCol = endingCol; (currentCol >= startingCol) && (count < total); currentCol--)
        {
            answer.push_back(vec[endingRow][currentCol]);
            count++;
        }
        endingRow--;

        // printing the starting column and then incrementing it:
        for (int currentRow = endingRow; (currentRow >= startingRow) && (count < total); currentRow--)
        {
            answer.push_back(vec[currentRow][startingCol]);
            count++;
        }
        startingCol++;
    } //TIME COMPLEXITY : O(rows*cols)

    return answer;
}

int main()
{
    vector<vector<int>> v = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    vector<vector<int>> v2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    vector<int> ans = spiralPrint(v);
    vector<int> ans2 = spiralPrint(v2);

    printVector(ans);
    printVector(ans2);
}