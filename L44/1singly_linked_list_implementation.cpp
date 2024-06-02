// implementation of singly linked list

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

    // constructor for creating a node pointing towards NULL:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor to delete a node (it is necessary because next is a pointer and we have to manually free up its space):
    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
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

// function to insert at head:
void insertAtHead(Node *&head, int data)
{
    // creating a new node pointing to NULL:
    Node *newNode = new Node(data);
    // pointing the pointer of this new node to the next node or the node which was previously at head:
    newNode->next = head;

    // now make head point towards this newly created node:
    head = newNode;
}

// function to insert at tail:
void insertAtTail(Node *&tail, int data)
{
    // creating a new node:
    Node *newNode = new Node(data);
    // pointing the pointer of previously last node to this newly created node:
    tail->next = newNode;

    // now make the tail point to this new node:
    tail = newNode;
}

// function to insert at any position:
void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{

    // miscellaneous case (if inserting at head):
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    // traversing the list to go to the position one behind than where the new node has to be inserted:
    Node *temp = head;
    int currentPosition = 1;
    while (currentPosition < position - 1)
    {
        temp = temp->next;
        currentPosition++;
    }

    // miscellaneous case (if inserting at tail):
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    // creating a new node:
    Node *newNode = new Node(data);

    // now point the pointer of this newNode to the next node in the list:
    newNode->next = temp->next;
    // now point the pointer of temp to this new node:
    temp->next = newNode;
}

// function to delete any Node from list by position:
void deleteNodeByPosition(Node *&head, Node *&tail, int position)
{
    // deleting the first position:
    if (position == 1)
    {
        // creating a temporary pointer to head:
        Node *temp = head;
        // pointing head to next node:
        head = head->next;
        // freeing up memory of the node to be deleted:
        temp->next = NULL;
        delete temp;
    }
    // deleting any other position:
    else
    {
        // traversing the list to go to the position where the new node has to be deleted:
        Node *current = head;
        Node *previous = NULL;
        int currentPosition = 1;
        while (currentPosition < position)
        {
            previous = current;
            current = current->next;
            currentPosition++;
        }

        // miscellaneous (if deleting tail node):
        if (current->next == NULL)
        {
            tail = previous;
        }

        // deleting the node and fixing the pointers before deleting it:
        previous->next = current->next;
        current->next = NULL;
        delete current;
    }
}

int main()
{
    // creating a node:
    Node *node1 = new Node(5);
    // head pointed to node1:
    Node *head = node1;
    // tail pointed to node1:
    Node *tail = node1;

    // cout << (*node1).data << node1->data << endl;
    // cout << (*node1).next << node1->next << endl;

    printLinkedList(head);

    insertAtHead(head, 2);

    printLinkedList(head);

    insertAtTail(tail, 12);

    printLinkedList(head);

    insertAtPosition(head, tail, 3, 22);

    printLinkedList(head);

    deleteNodeByPosition(head, tail, 2);

    printLinkedList(head);
}