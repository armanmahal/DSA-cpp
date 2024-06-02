// implementation of circular linked list :)
// THERE IS NO HEAD (only tail) IN CIRCULAR LINKED LIST

#include <iostream>
using namespace std;

// class to define a Node:
class Node
{
public:
    // data that node will store:
    int data;
    // pointer that will point to next node:
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

// function to print:
void printList(Node *&tail)
{
    Node *temp = tail;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}

// function to insert a node to a list based on the existing element (insert a node next to the element):
void insertNode(Node *&tail, int element, int data)
{
    // empty list:
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    // non empty list:
    // assume that the element ,(next to which the node has to be inserted), exists in the list.
    else
    {
        Node *current = tail;
        while (current->data != element)
        {
            current = current->next;
        }
        // element found after loop.

        // creating a new node:
        Node *newNode = new Node(data);
        newNode->next = current->next;
        current->next = newNode;
    }
}

// function to delete a node according to its value
void deleteNodeByValue(Node *&tail, int data)
{
    // if list is empty:
    if (tail == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }

    // assume that value to be deleted is present in the list
    Node *previous = tail;
    Node *current = tail->next;
    while (current->data != data)
    {
        previous = current;
        current = current->next;
    }

    // if tail is at the element to be deleted:
    if (tail == current)
    {
        tail = previous;
    }
    // if list is only of one node:
    else if (current == previous)
    {
        tail = NULL;
    }
    // removing the node by modifying pointers:
    previous->next = current->next;
    current->next = NULL;
    // deleting the node:
    delete current;
}

int main()
{
    Node *tail = NULL;

    insertNode(tail, 0, 3);
    printList(tail);

    insertNode(tail, 3, 5);
    printList(tail);

    insertNode(tail, 3, 5);
    printList(tail);

    insertNode(tail, 5, 9);
    printList(tail);

    deleteNodeByValue(tail, 5);
    printList(tail);
}