// given a stack and an element that we have to insert at its bottom.

#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// recursive function to insert element at bottom:
void solve(stack<int> &s, int element)
{
    // base case:
    if (s.empty())
    {
        s.push(element);
        return;
    }

    // storing current top element
    int top = s.top();

    // removing it and sending stack to recursive function:
    s.pop();
    solve(s, element);

    // adding the top element back to it after recursive call:
    s.push(top);
}

int main()
{
    stack<int> s;

    s.push(1);
    s.push(6);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(3);
    s.push(2);

    printStack(s);

    int element = 100;
    solve(s, 100);

    printStack(s);
}