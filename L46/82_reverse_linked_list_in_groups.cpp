/*
given a linked list , reverse it in 'k' groups
eg: if list is : head-->1,2,3,4,5,6,7-->NULL and k = 2
result: head-->2,1,4,3,6,5,7-->NULL
*/

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

Node *reverseLinkedList(Node *head, int k)
{
    // base case:
    // if size of list becomes 0 or 1:
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // first reversing k elements of the list:
    Node *temp = head;
    Node *current = head;
    Node *previous = NULL;
    for (int i = 0; i < k; i++)
    {
        if (current != NULL)
        {
            current = temp->next;
            temp->next = previous;
            previous = temp;
            temp = current;
        }
        // if current becomes NULL it means that list is over{ khatam hogi:) }
        else
        {
            return previous;
        }
    }

    // recursive call to reverse the rest of list:
    // after the loop, 'temp' will be pointing to the first element of the rest of the unsorted list , so it becomes head for the next recursive call
    // after the loop, we will require to attach the rest of the list next to the 'head' of the current list, so the recursive call becomes:
    head->next = reverseLinkedList(temp, k);

    // returning the head of currently reversed list , 'previous' will be pointing towards the head of currently reversed list:
    return previous;
}

int main()
{
    Node *node1 = NULL;

    insertAtHead(node1, 6);
    insertAtHead(node1, 5);
    insertAtHead(node1, 4);
    insertAtHead(node1, 3);
    insertAtHead(node1, 2);
    insertAtHead(node1, 1);
    insertAtHead(node1, 0);

    cout << "List: " << endl;
    printLinkedList(node1);

    Node *node1reversed = reverseLinkedList(node1, 5);
    node1 = NULL;

    cout << "After Reversing:" << endl;
    printLinkedList(node1reversed);

    delete node1;
    delete node1reversed;
}