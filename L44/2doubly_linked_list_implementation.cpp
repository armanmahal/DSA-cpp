// implementation of doubly linked list :)

#include <iostream>
using namespace std;

// class to define Node:
class Node
{
public:
    // data that node will store:
    int data;
    // pointer that will point to next node:
    Node *next;
    // pointer that will point to previous node:
    Node *prev;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    // destructor
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        if (prev != NULL)
        {
            delete prev;
            prev = NULL;
        }
    }
};

// function to print linked list:
void printLinkedList(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// function to find length of linked list:
int getLengthOfList(Node *&head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

// function to insert a node at head:
void insertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    head->prev = newNode;
    newNode->next = head;

    head = newNode;
}

// function to insert a node at tail:
void insertAtTail(Node *&tail, int data)
{
    Node *newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;

    tail = newNode;
}

// function to insert a node at any position:
void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    // if inserting at head:
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    // traversing to the correct position:
    Node *temp = head;
    int currentPosition = 1;
    while (currentPosition < position - 1)
    {
        temp = temp->next;
        currentPosition++;
    }

    // if inserting at tail:
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    // creating a new node at that position:
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// function for deletion of a node:
void deleteNodeByPosition(Node *&head, Node *&tail, int position)
{
    // deleting the first or head node:
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting the last or any other position node:
        Node *current = head;
        Node *previous = NULL;
        int currentPosition = 1;
        while (currentPosition < position)
        {
            previous = current;
            current = current->next;
            currentPosition++;
        }

        // if last position , changing tail:
        if (current->next == NULL)
        {
            tail = previous;
        }

        current->prev = NULL;
        if (current->next != NULL)
        {
            current->next->prev = previous;
        }
        previous->next = current->next;
        current->next = NULL;

        delete current;
    }
}

int main()
{
    Node *node1 = new Node(6);
    Node *head = node1;
    Node *tail = node1;

    printLinkedList(head);
    cout << "length: " << getLengthOfList(head) << endl;

    insertAtHead(head, 3);
    printLinkedList(head);
    cout << "length: " << getLengthOfList(head) << endl;

    insertAtHead(head, 2);
    printLinkedList(head);
    cout << "length: " << getLengthOfList(head) << endl;

    insertAtTail(tail, 10);
    printLinkedList(head);
    cout << "length: " << getLengthOfList(head) << endl;

    insertAtPosition(head, tail, 1, 0);
    printLinkedList(head);
    cout << "length: " << getLengthOfList(head) << endl;

    insertAtPosition(head, tail, 4, 200);
    printLinkedList(head);
    cout << "length: " << getLengthOfList(head) << endl;

    deleteNodeByPosition(head, tail, 6);
    printLinkedList(head);
    cout << "length: " << getLengthOfList(head) << endl;

    deleteNodeByPosition(head, tail, 1);
    printLinkedList(head);
    cout << "length: " << getLengthOfList(head) << endl;

    deleteNodeByPosition(head, tail, 3);
    printLinkedList(head);
    cout << "length: " << getLengthOfList(head) << endl;
}