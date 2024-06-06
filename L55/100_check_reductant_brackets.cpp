// Expression contains redundant bracket or not

/*
Given a string of balanced expressions, find if it contains a redundant parenthesis or not. A set of parenthesis is redundant if the same sub-expression is surrounded by unnecessary or multiple brackets. Print ‘Yes‘ if redundant, else ‘No‘.

Note: Expression may contain ‘+‘, ‘*‘, ‘–‘ and ‘/‘ operators. Given expression is valid and there are no white spaces present.
*/

// EXAMPLES
/*
Input: str = “((a+b))”
Output: YES
Explanation: ((a+b)) can reduced to (a+b), this Redundant

Input: str = “(a+(b)/c)”
Output: YES
Explanation: (a+(b)/c) can reduced to (a+b/c) because b is surrounded by () which is redundant.
*/

// APPROACH : using stack.

#include <iostream>
#include <stack>
using namespace std;

bool checkReductant(string s)
{
    stack<char> stack;

    // iterating the string:
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        // if it is an opening bracket or an operator:
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            // push it to the stack:
            stack.push(ch);
        }
        // if it is an closing bracket:
        else if (ch == ')')
        {
            // check for reducatancy:

            // top element of stack:
            char top = stack.top();
            // bool to represent if reductant or not:
            bool isReductant = true;
            // iterating the stack until a opening bracket is found:
            while (stack.top() != '(')
            {
                // if before finding an opening bracket we found an operator then it was not reductant:
                if (top == '+' || top == '-' || top == '*' || top == '/')
                {
                    isReductant = false;
                }
                // remove the current operator from stack:
                stack.pop();
            }
            // after the above loop , the top will be an opening bracket, since we have found its corresponding closing bracket , so we can remove the pair:
            stack.pop();

            // if after the loop , isReductant remains true, i.e. if no operator was found between two brackets then it is reductant so return true:
            if (isReductant)
            {
                return true;
            }
        }
        // if it a lowercase letter:
        else
        {
            // just skip it:
            continue;
        }
    }
    // if out of loop then it is not reductant
    return false;
}

int main()
{
    string s1 = "((a+b)-((a*c))";
    string s2 = "((a*b)+(a*b))";

    cout << checkReductant(s1) << endl;
    cout << checkReductant(s2) << endl;
}