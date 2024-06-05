// implementation of stacks using arrays:

#include <iostream>
using namespace std;

class Stack
{
private:
    // properties:

    // pointer to the array:
    int *arr;
    // to indicate the top element of the stack:
    int top;
    // to indicate the size of stack:
    int size;

public:
    // constructor:
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // functionality:
    //  to add an element to the top of stack
    void push(int element)
    {
        // check whether stack has empty space
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    // to remove the top element of stack:
    void pop()
    {
        // check that the stack should not be empty
        if (top > -1)
        {
            top--;
        }
        else
        {
            cout << "Stack Empty" << endl;
        }
    }

    // to get the top element of stack:
    int peek()
    {
        if (top >= 0)
            return arr[top];
        else
        {
            cout << "Stack Empty" << endl;
            return -1;
        }
    }

    // to check if stack is empty or not:
    bool isEmpty()
    {
        if (top == -1)
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
    Stack s(4);

    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.peek() << endl;
    cout << s.isEmpty() << endl;
}