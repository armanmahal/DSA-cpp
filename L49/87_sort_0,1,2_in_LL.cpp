// given a linked list containing 0,1,2 in random order , sort it.
// TWO APPROACHES DONE

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

// APPROACH ONE : counting number of 0,1,2 in LL
void sortLinkedList(Node *&head)
{
    int zeroCnt = 0;
    int oneCnt = 0;
    int twoCnt = 0;

    // traversing list to count 0,1,2:
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroCnt++;
        }
        else if (temp->data == 1)
        {
            oneCnt++;
        }
        else
        {
            twoCnt++;
        }
        temp = temp->next;
    }

    // inserting the 0,1,2s LL:
    temp = head;
    while (temp != NULL)
    {
        if (zeroCnt != 0)
        {
            temp->data = 0;
            zeroCnt--;
        }
        else if (oneCnt != 0)
        {
            temp->data = 1;
            oneCnt--;
        }
        else if (twoCnt != 0)
        {
            temp->data = 2;
            twoCnt--;
        }

        temp = temp->next;
    }
}

// APPROACH TWO: storing 0,1,2 in three different linked lists and then merging those:
Node *sortLinkedList2(Node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }

    // initialize three temporary nodes for 0,1,2:
    Node *headZero = new Node(-1);
    Node *tailZero = headZero;
    Node *headOne = new Node(-1);
    Node *tailOne = headOne;
    Node *headTwo = new Node(-1);
    Node *tailTwo = headTwo;

    // traversing the LL to create three different linked lists for 0,1,2:
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            tailZero->next = temp;
            tailZero = temp;
            temp = temp->next;
            tailZero->next = NULL;
        }
        else if (temp->data == 1)
        {
            tailOne->next = temp;
            tailOne = temp;
            temp = temp->next;
            tailOne->next = NULL;
        }
        else if (temp->data == 2)
        {
            tailTwo->next = temp;
            tailTwo = temp;
            temp = temp->next;
            tailTwo->next = NULL;
        }
    }

    // merging the three lists:

    // if list of 'one' is empty (skip it):
    if (headOne->next == NULL)
    {
        tailZero->next = headTwo->next;
    }
    // if list of 'one' is not empty
    else
    {
        tailZero->next = headOne->next;
        tailOne->next = headTwo->next;
    }

    // deleting the temporary node:
    Node *returningHead = headZero->next;

    headZero->next = NULL;
    delete headZero;
    headOne->next = NULL;
    delete headOne;
    headTwo->next = NULL;
    delete headTwo;

    // returning head of sorted list:
    return returningHead;
}

int main()
{
    Node *node1 = NULL;
    insertAtHead(node1, 1);
    insertAtHead(node1, 2);
    insertAtHead(node1, 0);
    insertAtHead(node1, 2);
    insertAtHead(node1, 1);
    insertAtHead(node1, 2);
    insertAtHead(node1, 0);
    insertAtHead(node1, 2);
    insertAtHead(node1, 1);
    insertAtHead(node1, 1);
    insertAtHead(node1, 0);
    insertAtHead(node1, 0);

    printLinkedList(node1);

    // APPROACH 1:
    /*sortLinkedList(node1)*/

    // APPROACH 2 :
    Node *sorted = sortLinkedList2(node1);

    printLinkedList(sorted);

    delete node1;
}