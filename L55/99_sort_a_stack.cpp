// given a stack containing some integers, sort it using recursions.

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

// function to insert an element in the correct position in the sorted stack:
void insert(stack<int> &s, int element)
{
    // base cases:
    // if stack becomes empty:
    if (s.empty())
    {
        s.push(element);
        return;
    }
    // if the current top element of stack is greater then the element to be inserted:
    if (s.top() >= element)
    {
        s.push(element);
        return;
    }

    // else store the current top element and make recursive call to check in the remaining stack:
    int top = s.top();
    s.pop();
    insert(s, element);
    // adding the top element after recursive call:
    s.push(top);
}
// function to sort the stack
void sort(stack<int> &s)
{
    // base case:
    if (s.empty())
    {
        return;
    }

    // storing the top element:
    int top = s.top();
    // removing the top element
    s.pop();

    // recursive call to sort the rest of the stack:
    sort(s);

    // inserting the top element in the correct position in the rest of sorted stack:
    insert(s, top);
}

int main()
{
    stack<int> s;

    s.push(0);
    s.push(1);
    s.push(6);
    s.push(5);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(3);
    s.push(0);

    printStack(s);

    // function to sort:
    sort(s);

    printStack(s);
}