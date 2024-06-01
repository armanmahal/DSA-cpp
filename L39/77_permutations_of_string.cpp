// given a string , find its all permutations.
//"abc"---> "abc","acb","bac","bca","cab","cba"

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

void permutations(string &s, vector<string> &ans, int index = 0)
{
    // base case:
    if (index >= s.length())
    {
        ans.push_back(s);
        return;
    }

    // swapping the current letter with all other letters:
    for (int i = index; i < s.length(); i++)
    {
        swap(s[i], s[index]);
        // recursive call for next index:
        permutations(s, ans, index + 1);
        // backtracking: to undo the last swap:
        swap(s[i], s[index]);
    }
}

int main()
{
    string s = "abc";
    vector<string> ans;

    permutations(s, ans);

    printStringVector(ans);
}