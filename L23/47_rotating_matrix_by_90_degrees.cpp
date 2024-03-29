// given a n x n square matrix, rotate it clockwise by 90 degrees.

#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>> v)
{
    int rows = v.size();
    int cols = v[0].size();

    for (int i = 0; i < rows; i++)
    {
        cout << "|";
        for (int j = 0; j < cols; j++)
        {
            cout << v[i][j] << "|";
        }
        cout << endl;
    }
}

//pass the vector by 'pass by reference'
void rotateMatrix(vector<vector<int>> &v)
{
    // as it is a square matrix:
    int n = v.size();

    //transpose the matrix:
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            swap(v[i][j], v[j][i]);
        }
    }

    //reverse each row:
    for(int i = 0 ; i < n/2; i++){
        for(int j = 0; j < n; j++){
            swap(v[j][i],v[j][n-1-i]);
        }
    }

}

int main()
{
    vector<vector<int>> v = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    cout << "before Rotating:" << endl;
    printMatrix(v);

    rotateMatrix(v);

    cout << "after Rotating:" << endl;
    printMatrix(v);
    cout<<endl;

    vector<vector<int>> v2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10 ,11, 12},
        {13, 14,15, 16}};

    cout << "before Rotating:" << endl;
    printMatrix(v2);

    rotateMatrix(v2);

    cout << "after Rotating:" << endl;
    printMatrix(v2);
    cout<<endl;

}