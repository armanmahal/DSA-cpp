// Given a string containing digits from 2-9 inclusive,
// return all possible letter combinations that the number could represent.
// A mapping of digits to letters is just like on the telephone buttons
/*
Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

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

void solve(string &numbers, vector<string> &ans, string &output, string *map, int index = 0)
{
    // base case:
    if (index >= numbers.length())
    {
        ans.push_back(output);
        return;
    }

    // getting the letter mapped with current number
    int number = numbers[index] - '0';
    string letters = map[number];

    // for loop to add the alphabets linked with current number to the output string one by one:
    for (int i = 0; i < letters.length(); i++)
    {
        output.push_back(letters[i]);
        solve(numbers, ans, output, map, index + 1);
        // backtrack to remove the last added letter to output string because now its work is done.
        output.pop_back();
    }
}

int main()
{
    string numbers = "23";

    vector<string> ans;

    string output = "";

    string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    solve(numbers, ans, output, map);

    printStringVector(ans);
}