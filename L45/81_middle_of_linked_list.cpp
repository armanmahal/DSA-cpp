// finding middle of linked list. (2 approaches done)

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

// finding middle APPROACH 1 (using length of list):
int findMiddle1(Node *&head)
{
    // if list contain zero or one node:
    if (head == NULL || head->next == NULL)
    {
        return head->data;
    }

    // finding length of list:
    int length = 1;
    Node *temp = head;
    while (temp->next != NULL)
    {
        length++;
        temp = temp->next;
    }

    // finding the middle element:
    int middle = (length / 2) + 1;
    int count = 1;
    temp = head;
    while (count < middle)
    {
        temp = temp->next;
        count++;
    }
    // after this loop temp should be pointing to middle node:
    return temp->data;
}

// finding middle APPROACH 2 (using two iterators):
int findMiddle2(Node *&head)
{
    // if list contain zero or one node:
    if (head == NULL || head->next == NULL)
    {
        return head->data;
    }

    // iterating the list using two pointers:
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL)
    {
        // increasing fast by two:
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        // increasing slow by one:
        slow = slow->next;
    }
    // after this loop slow will be pointing towards the middle:
    return slow->data;
}

int main()
{
    Node *node1 = NULL;
    insertAtHead(node1, 7);
    insertAtHead(node1, 6);
    insertAtHead(node1, 5);
    insertAtHead(node1, 4);
    insertAtHead(node1, 3);
    insertAtHead(node1, 2);
    insertAtHead(node1, 1);

    Node *node2 = NULL;
    insertAtHead(node2, 6);
    insertAtHead(node2, 5);
    insertAtHead(node2, 4);
    insertAtHead(node2, 3);
    insertAtHead(node2, 2);
    insertAtHead(node2, 1);

    // APPROACH 1
    printLinkedList(node1);
    cout << "middle:" << findMiddle1(node1) << endl;
    printLinkedList(node2);
    cout << "middle:" << findMiddle1(node2) << endl;

    // APPROACH 2
    printLinkedList(node1);
    cout << "middle:" << findMiddle2(node1) << endl;
    printLinkedList(node2);
    cout << "middle:" << findMiddle2(node2) << endl;
}