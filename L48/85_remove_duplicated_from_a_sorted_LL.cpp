// given a SORTED LL , remove all the duplicate elements from it.

#include <iostream>
#include <map>
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

// FUNCTION TO REMOVE DUPLICATED FROM A SORTED LL:
void removeDuplicate(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        // if next element is same:
        if ((temp->next != NULL) && temp->data == temp->next->data)
        {
            // delete that node :
            Node *nodeToDelete = temp->next;
            Node *nextNode = temp->next->next;
            temp->next = nextNode;
            nodeToDelete->next = NULL;
            delete nodeToDelete;
        }
        // if next element not same:
        else
        {
            temp = temp->next;
        }
    }
}

int main()
{
    Node *node1 = NULL;
    insertAtHead(node1, 4);
    insertAtHead(node1, 4);
    insertAtHead(node1, 4);
    insertAtHead(node1, 4);
    insertAtHead(node1, 4);
    insertAtHead(node1, 3);
    insertAtHead(node1, 3);
    insertAtHead(node1, 3);
    insertAtHead(node1, 3);
    insertAtHead(node1, 2);
    insertAtHead(node1, 1);
    insertAtHead(node1, 1);

    printLinkedList(node1);

    removeDuplicate(node1);

    printLinkedList(node1);

    delete node1;
}
