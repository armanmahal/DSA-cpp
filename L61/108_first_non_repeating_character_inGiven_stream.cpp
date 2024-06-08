/*
Given an input stream A of n characters consisting only of lower case alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.
*/

/*
Example 1:

Input: A = "aabc"
Output: "a#bb"
Explanation: For every ith character we will
consider the string from index 0 till index i first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - there are two non repeating characters 'b' and 'c',
first non-repeating character is 'b' because 'b' comes before
'c' in the stream.
*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

string solve(string s)
{

    string ans = "";
    int count[26] = {0};
    queue<int> q;

    for (int i = 0; i < s.size(); i++)
    {

        char currentChar = s[i];

        // increasing the count of current element
        count[currentChar - 'a']++;

        // pushing the current element to the queue
        q.push(currentChar);

        // checking the queue for nonrepeating elements:
        while (!q.empty())
        { // non repeating char found:
            if (count[q.front() - 'a'] == 1)
            {
                ans.push_back(q.front());
                break;
            } // repeating char found:
            else
            {
                q.pop();
            }
        }

        // if after above loop the queue is empty then it means that no repeating char was found:
        if (q.empty())
        {
            ans.push_back('#');
        }
    }

    return ans;
}

int main()
{
    string s1 = "aabc";
    string ans1 = solve(s1);
    cout << ans1 << endl;

    string s2 = "zz";
    string ans2 = solve(s2);
    cout << ans2 << endl;
}