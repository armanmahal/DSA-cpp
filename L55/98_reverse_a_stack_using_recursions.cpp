// given a stack containing some integers, reverse it using recursions.

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

// function to insert the elment at bottom:
void insertAtBottom(stack<int> &s, int x)
{
    // base case:
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int top = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(top);
}
// function to reverse:
void reverse(stack<int> &s)
{
    // base case:
    if (s.empty())
    {
        return;
    }

    // storing the top element:
    int top = s.top();

    // removing the top element:
    s.pop();

    // recursive call to reverse the rest of stack:
    reverse(s);

    // now move the stored element to the bottom of the stack:
    insertAtBottom(s, top);
}

int main()
{
    stack<int> s;

    s.push(1);
    s.push(6);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);

    printStack(s);

    // function to reverse:
    reverse(s);

    printStack(s);
}