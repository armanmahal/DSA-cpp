// implementation of queue class.

#include <iostream>
using namespace std;

class Queue
{
private:
    // array to store elements:
    int *arr;
    int size;
    // index to denote the first element of queue:
    int front;
    // index to denote the last element of queue:
    int rear;

public:
    // constructor:
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    // function to push an element:
    void push(int data)
    {
        // if queue if full:
        if (rear == size)
        {
            cout << "Queue is Full" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    // function to remove the first elment:
    void pop()
    {
        // if empty:
        if (front == rear)
        {
            cout << "queue is empty" << endl;
        }
        else
        {
            arr[front] = -1;
            front++;

            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    //function to get front element
    int first()
    {
        if (front == rear)
        {
            cout << "Empty" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Queue q(5);

    cout<<q.isEmpty()<<endl;

    q.push(1);
    q.push(2);
    q.push(3);

    cout<<q.isEmpty()<<endl;

    cout<<q.first()<<endl;

    q.pop();

    cout<<q.first()<<endl;

}