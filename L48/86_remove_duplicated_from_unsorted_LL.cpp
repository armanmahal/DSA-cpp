// given a UNSORTED LL , remove all the duplicate elements from it.

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

// FUNCTION TO REMOVE DUPLICATED FROM A UNSORTED LL:
void removeDuplicate(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    // iterating the LL :
    Node *current = head;
    while (current != NULL)
    {
        int element = current->data;

        Node *temp = current;
        while (temp->next != NULL)
        {
            // if element repeats
            if (temp->next->data == element)
            {
                Node *nodeToDelete = temp->next;
                Node *next = temp->next->next;
                temp->next = next;
                nodeToDelete->next = NULL;
                delete nodeToDelete;
            }
            // else if element is not repeating-one
            else
            {
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

int main()
{
    Node *node1 = NULL;
    insertAtHead(node1, 10);
    insertAtHead(node1, 10);
    insertAtHead(node1, 1);
    insertAtHead(node1, 3);
    insertAtHead(node1, 3);
    insertAtHead(node1, 6);
    insertAtHead(node1, 2);
    insertAtHead(node1, 2);
    insertAtHead(node1, 2);
    insertAtHead(node1, 6);
    insertAtHead(node1, 3);
    insertAtHead(node1, 5);
    insertAtHead(node1, 4);
    insertAtHead(node1, 3);
    insertAtHead(node1, 3);
    insertAtHead(node1, 2);
    insertAtHead(node1, 1);
    insertAtHead(node1, 0);

    printLinkedList(node1);

    removeDuplicate(node1);

    printLinkedList(node1);

    delete node1;
}