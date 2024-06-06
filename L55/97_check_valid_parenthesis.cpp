// given a string containing some set of parenthesis ,
// check if they are valid are not.
// eg: "[{()}]()" ---> valid ,
//     "[{}{(})]"---> not valid

#include <iostream>
#include <stack>
using namespace std;

bool checkValidParenthesis(string s)
{
    stack<char> stack;

    // iterating the string :
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        // if opening bracket:
        if (ch == '(' || ch == '{' || ch == '[')
        {
            stack.push(ch);
        }

        // if closing bracket:
        else
        {
            // check the stack should not be empty if a closing bracket comes:
            if (!stack.empty())
            {
                // check if the last element in stack is a corresponding opening bracket to current ch:
                if ((ch == ')' && stack.top() == '(') || (ch == '}' && stack.top() == '{') || (ch == ']' && stack.top() == '['))
                {
                    // then remove the bracket from stack because the pair is complete:
                    stack.pop();
                }
                else
                {
                    // if there is no corresponding bracket:
                    return false;
                }
            }
            else
            {
                // if stack is empty and a closing bracket comes:
                return false;
            }
        }
    }

    // after loop the stack should be empty:
    if (stack.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s1 = "[{(())()}()]";
    string s2 = "[{(})]";

    cout << checkValidParenthesis(s1) << endl;
    cout << checkValidParenthesis(s2) << endl;
}