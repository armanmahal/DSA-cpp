// Interleave the first half of the queue with second half

/*
Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.
*/

// Examples:
/*
Input :  1 2 3 4
Output : 1 3 2 4

Input : 11 12 13 14 15 16 17 18 19 20
Output : 11 16 12 17 13 18 14 19 15 20
*/

// NOTE: QUEUE IS OF EVEN LENGTH

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

// APPROACH: Using an another queue:
void interLeave(queue<int> &q)
{
    // store the first half of original queue to a temp queue:
    queue<int> temp;
    int size = q.size();
    for (int i = 0; i < size / 2; i++)
    {
        temp.push(q.front());
        q.pop();
    }

    // Till the temp queue is empty
    // 1. Pop the front of the temp queue and push it to the original queue
    // 2. Pop the front of the original queue and push it to the original queue

    while (!temp.empty())
    {
        q.push(temp.front());
        temp.pop();
        q.push(q.front());
        q.pop();
    }
}

// APPROACH: Using a stack:
void interLeave2(queue<int> &q)
{
    // Initialize an empty stack of int type
    stack<int> s;
    int halfSize = q.size() / 2;

    // Push first half elements into the stack
    // queue:16 17 18 19 20, stack: 15(T) 14 13 12 11
    for (int i = 0; i < halfSize; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // enqueue back the stack elements
    // queue: 16 17 18 19 20 15 14 13 12 11
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    // dequeue the first half elements of queue
    // and enqueue them back
    // queue: 15 14 13 12 11 16 17 18 19 20
    for (int i = 0; i < halfSize; i++)
    {
        q.push(q.front());
        q.pop();
    }

    // Again push the first half elements into the stack
    // queue: 16 17 18 19 20, stack: 11(T) 12 13 14 15
    for (int i = 0; i < halfSize; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // interleave the elements of queue and stack
    // queue: 11 16 12 17 13 18 14 19 15 20
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    printQueue(q);

    interLeave(q);

    printQueue(q);
}