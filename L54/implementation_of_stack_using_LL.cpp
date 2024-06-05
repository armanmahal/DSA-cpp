// implementation of a stack using linked lists.

#include <iostream>
using namespace std;

struct Node
{
    Node *next;
    int data;

    // constructor:
    Node(int element)
    {
        this->data = element;
        this->next = NULL;
    }
};

class Stack
{
private:
    // properties:
    Node *top;

public:
    // constructor:
    Stack()
    {
        this->top = NULL;
    }

    // functionality:
    void push(int element)
    {
        Node *newNode = new Node(element);
        if (top == NULL)
        {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }

    void pop()
    {
        // check the LL should not be empty:
        if (top == NULL)
        {
            cout << "Stack Empty" << endl;
            return;
        }
        // if LL is of single element:
        if (top->next == NULL)
        {
            delete top;
            top->next = NULL;
        }
        else
        {
            Node *temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
        }
    }

    int peek()
    {
        if (top == NULL)
        {
            cout << "stack empty" << endl;
            return -1;
        }
        else
        {
            return top->data;
        }
    }

    bool isEmpty()
    {
        if (top == NULL)
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
    Stack s;

    cout << s.isEmpty() << endl;

    s.push(1);
    s.push(5);
    s.push(3);

    cout << s.isEmpty() << endl;

    cout << s.peek() << endl;

    s.pop();

    cout << s.peek() << endl;
}