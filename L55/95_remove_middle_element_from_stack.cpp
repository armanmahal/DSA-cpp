// given a stack remove its middle element:

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

// recursive function to remove middle element:
void solve(stack<int> &s, int size, int count = 0)
{
    // base case:
    if (count == size / 2)
    {
        s.pop();
        return;
    }

    int element = s.top();
    s.pop();
    // recursive call:
    solve(s, size, count + 1);

    // adding the current element back to the top:
    s.push(element);
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

    // function to remove middle:
    solve(s, s.size());

    printStack(s);
}