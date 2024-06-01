// The problem of generating all subsequences of a string is similar to
// the problem of generating all subsets of a set
/*
Subsequences of "abc":
abc
ab
ac
a
bc
b
c
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print2dVector(vector<string> vec)
{
    cout << "[ ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " , ";
    }
    cout << " ]" << endl;
}

void solve(string str, vector<string> &ans, string &output, int index = 0)
{
    // base case:
    if (index >= str.length())
    {
        ans.push_back(output);
        return;
    }

    // exluding the current index:
    solve(str, ans, output, index + 1);
    
    // including the current index:
    output.push_back(str[index]);
    solve(str, ans, output, index + 1);
    output.pop_back();
}

int main()
{
    string s = "abc";

    vector<string> ans;

    string output = "";

    solve(s, ans, output);

    print2dVector(ans);
}