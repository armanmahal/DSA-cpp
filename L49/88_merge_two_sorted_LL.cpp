// given two sorted linked lists, merge them to one list that should come out to be sorted.

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

// function to merge two sorted LL:
Node *mergeLists(Node *&head1, Node *&head2)
{
    // set head1 to the list which has its element smaller than other:
    if (head1->data > head2->data)
    {
        Node *temp = head1;
        head1 = head2;
        head2 = temp;
    }

    // now grab each element of second list and keep inserting them to the right position in the list 1:
    Node *current1 = head1;
    Node *current2 = head2;
    while (current2 != NULL && current1->next != NULL)
    {
        int currentElement = current2->data;
        // if found the correct position of currentElement:
        if (currentElement >= current1->data && currentElement <= current1->next->data)
        {
            Node *temp = current1->next;
            current1->next = current2;
            Node *temp2 = current2->next;
            current2->next = temp;
            current2 = temp2;
            current1 = current1->next;
        }
        // if not the correct position:
        else
        {
            current1 = current1->next;
        }
    }

    // now check if some elements of list2 that are larger than then largest element of list1 are still left, then add them at last:
    if (current2 != NULL)
    {
        current1->next = current2;
    }

    // returning the head node of list1:
    return head1;
}

int main()
{
    Node *list1 = NULL;
    insertAtHead(list1, 19);
    insertAtHead(list1, 19);
    insertAtHead(list1, 15);
    insertAtHead(list1, 9);
    insertAtHead(list1, 0);
    Node *list2 = NULL;
    insertAtHead(list2, 19);
    insertAtHead(list2, 19);
    insertAtHead(list2, 19);
    insertAtHead(list2, 17);
    insertAtHead(list2, 2);
    insertAtHead(list2, 1);

    printLinkedList(list1);
    printLinkedList(list2);

    Node *merged = mergeLists(list1, list2);

    printLinkedList(merged);

    delete merged;
}