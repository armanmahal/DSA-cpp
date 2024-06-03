// to reverse a linked list:

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

void reverseLinkedList(Node *&head)
{
    // if size of list is 0 or 1:
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    Node *previous = NULL;
    Node *current = head;
    while (head != NULL)
    {
        current = head->next;
        head->next = previous;
        previous = head;
        head = current;
    }
    head = previous;
}

int main()
{
    Node *node1 = NULL;

    insertAtHead(node1, 3);
    insertAtHead(node1, 2);
    insertAtHead(node1, 1);
    insertAtHead(node1, 0);

    cout << "List: " << endl;
    printLinkedList(node1);

    reverseLinkedList(node1);

    cout << "After Reversing:" << endl;
    printLinkedList(node1);
}