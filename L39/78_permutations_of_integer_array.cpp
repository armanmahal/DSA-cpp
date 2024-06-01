// given an array of intergers,
// return all the possible arrays with all the permuations of the numbers
// that are contained in the original array

#include <iostream>
#include <vector>
using namespace std;

void print2dVector(vector<vector<int>> vec)
{
    cout << "[" << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "{ ";
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << "}" << endl;
    }
    cout << "]" << endl;
}

void permutations(vector<int> &arr, vector<vector<int>> &ans, int index = 0)
{
    // base case:
    if (index >= arr.size())
    {
        ans.push_back(arr);
        return;
    }

    // swapping the digit at current index with all the next digits, including it:
    for (int i = index; i < arr.size(); i++)
    {
        swap(arr[i], arr[index]);
        // recursive call
        permutations(arr, ans, index + 1);
        // backtracking:
        swap(arr[i], arr[index]);
    }
}

int main()
{
    vector<int> arr = {1, 2, 3};

    vector<vector<int>> ans;

    permutations(arr, ans);

    print2dVector(ans);
}