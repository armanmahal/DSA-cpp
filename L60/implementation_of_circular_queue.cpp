// implementation of class for circular queue:

#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *arr;
    int size;
    int front;
    int rear;

public:
    // constructor:
    CircularQueue(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    // function to add element to queue:
    void push(int element)
    {
        // checking if queue is full:
        if ((front == 0 && rear == size - 1) || (rear + 1) == front)
        {
            cout << "Queue is FUll" << endl;
            return;
        }
        // if pushing the first element:
        else if (front == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = element;
        }
        // if rear has reached the end of array , but there is space available at beginning:
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = element;
        }
        // else the normal case that there is available space :
        else
        {
            rear++;
            arr[rear] = element;
        }
    }

    // function to remove an element from queue:
    void pop()
    {
        // if queue is empty:
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        // if there is single element in the queue:
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        // if front is at last element of array:
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        // else the normal case:
        else
        {
            arr[front] = -1;
            front++;
        }
    }
};

int main()
{
}