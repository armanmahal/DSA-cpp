// given a list , check if it is circular or not? just return true or false

// NOTE: a list is circular if it has no node having its next pointer to NULL
// NOTE: consider an empty list as circular
// CONSTRAINTS: all the elements inside the list is unique, i.e. there are no duplicate elements.

#include <iostream>
using namespace std;

// implementation of node class:
class Node
{
public:
    int data;
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

void printCircularLinkedList(Node *&head)
{
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void insertAtHead(Node *&head, int value)
{
    if (head == NULL)
    {
        Node *newNode = new Node(value);
        head = newNode;
        return;
    }
    else
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
}

// function to create a circular linked list:
void createCircularList(Node *&head, int *arr, int size)
{

    for (int i = size - 1; i >= 0; i--)
    {
        int element = arr[i];
        if (head == NULL)
        {
            Node *newNode = new Node(element);
            head = newNode;
            newNode->next = newNode;
        }
        else
        {
            Node *newNode = new Node(element);
            Node *temp = head->next;
            head->next = newNode;
            head = newNode;
            head->next = temp;
        }
    }
}

// CHEKCING CIRCULAR LIST OR NOT:
bool checkList(Node *&head)
{
    // if empty list:
    if (head == NULL)
    {
        return true;
    }

    // traversing the list until one condition met:
    Node *temp = head;
    do
    {
        temp = temp->next;
    } while (temp != NULL && temp != head);

    // if temp stops at NULL it means it was not circular:
    // and if temp stops at head it means temp came back to its position hence the list was circular:
    if (temp == head)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // creating a singly linked list:
    Node *node1 = NULL;
    insertAtHead(node1, 4);
    insertAtHead(node1, 3);
    insertAtHead(node1, 2);
    insertAtHead(node1, 1);
    insertAtHead(node1, 0);

    printLinkedList(node1);
    cout << checkList(node1) << endl;

    // creating a ciruclar linked list:
    Node *node2 = NULL;
    int size = 5;
    int arr[size] = {1,2,3,4,5};
    createCircularList(node2, arr, size);

    printCircularLinkedList(node2);
    cout << checkList(node2) << endl;

    delete node1;
}