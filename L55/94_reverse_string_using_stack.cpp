// given a string, reverse it using a stack:

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string s = "hello";

    stack<char> stack;

    // we know stack has a property that whenever we put some items into a stack it will return back those items in reverse order

    // putting characters of string into stack:
    for (int i = 0; i < s.length(); i++)
    {
        stack.push(s[i]);
    }

    // getting back the chars from stack
    string ans = "";
    while (!stack.empty())
    {
        ans = ans + stack.top();
        stack.pop();
    }

    cout << ans << endl;
}