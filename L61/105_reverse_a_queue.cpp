// given a queue, reverse its element:

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void printQueue(queue<int> q)
{
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

// APPROACH 1 : using a stack
void reverseUsingStack(queue<int> &q)
{
    stack<int> s;

    // putting elements to the stack:
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    // getting the elements back from the stack:
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    printQueue(q);

    reverseUsingStack(q);

    printQueue(q);
}