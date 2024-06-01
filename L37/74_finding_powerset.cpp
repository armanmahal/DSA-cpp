// given a array of numbers , return a powerset array containing all the subsets of that given array of numbers
// eg:- {1,2,3} ---> { {},{1},{2},{3},{1,2},{2,3},{1,3},{1,2,3} }
// note: There are 2^n subsets of given array of number, where n is the number of elements in that array/set.

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

void solve(vector<int> &vec, vector<int> &output, vector<vector<int>> &ans, int index = 0)
{
    // base case:
    if (index >= vec.size())
    {
        ans.push_back(output);
        return;
    }

    // excluding the current index element:
    solve(vec, output, ans, index + 1);

    // including the current index element:
    output.push_back(vec[index]);
    solve(vec, output, ans, index + 1);
    output.pop_back(); // Backtrack: remove the last element added
}

int main()
{

    vector<int> vec = {1, 2, 3};

    // creating a vector for answer:
    vector<vector<int>> ans;

    vector<int> output;

    solve(vec, output, ans);

    print2dVector(ans);

    return 0;
}