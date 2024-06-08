// given a queue and and an integer k
//  reverse the first k elements of the queue

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

void reverse(queue<int>& q, int k){
    //creating a stack :
    stack<int> stack;

    //storing first k elements of queue into stack:
    for(int i = 0; i < k; i++){
        stack.push(q.front());
        q.pop();
    }

    //inserting back the values from the stack to queue:
    while(!stack.empty()){
        q.push(stack.top());
        stack.pop();
    }

    //taking the (q.size()-k) left elements and putting them at the back of queue , because now they have come at the front of queue:

    for(int i = 0; i < q.size()-k ; i++){
        q.push(q.front());
        q.pop();
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

    int k = 3;

    printQueue(q);

    reverse(q, k);

    printQueue(q);
}