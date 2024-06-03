/*
given a linked list, do the following
1- detect if a loop is present or not in it
2- find the starting node of that loop
3- remove the loop from LL
*/

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

// detecting a loop with iterative approach:
bool detectLoop(Node *&head)
{
    if (head == NULL)
    {
        return false;
    }

    // create a map to stored address of visited nodes:
    map<Node *, bool> visited;

    // traversing the LL:
    Node *temp = head;
    while (temp != NULL)
    {
        // loop is present:
        if (visited[temp] == true)
        {
            return true;
        }
        // storing the node in map as true:
        visited[temp] = true;

        temp = temp->next;
    }
    // if out of loop that means temp == NULL, so there is no loop:
    return false;
}

// detecting a loop with Floyd Cycle Detection (contant space complexity):
Node *detectLoopByFloydCycleDetection(Node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }

    // traversing the LL with two pointers, one slow and one fase:
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        // increasing fast by two:
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        // if slow equals fast , then loop is definitely there:
        if (slow == fast)
        {
            return slow;
        }
    }

    // if out of while loop, then loop in LL is not present:
    return NULL;
}

// function to find the starting node of the loop in LL:
Node *findTheStartOfLoop(Node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }

    // setting two pointers:
    // one to the node of intersection that we get from floyd method,
    // second to the start of LL:
    Node *intersection = detectLoopByFloydCycleDetection(head);
    Node *start = head;

    // initialize a loop until start and intersection pointers meet:
    while (start != intersection)
    {
        start = start->next;
        intersection = intersection->next;
    }
    // after loop start or intersection shall be pointing to the point of start of CYcle of LL:
    return start;
}

// function to remove the loop from LL:
void removeLoop(Node *&head)
{
    if (head == NULL)
    {
        return;
    }

    // getting the start node of the loop:
    Node *startOfLoop = findTheStartOfLoop(head);

    // iterating the loop to point the last node to NULL:
    Node *temp = startOfLoop;
    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }
    // after this loop will be pointing to the last element of loop, so point it to null:
    temp->next = NULL;
}

int main()
{
    // creating a linked list with loop:
    Node *node1 = NULL;
    insertAtHead(node1, 6);
    insertAtHead(node1, 5);
    insertAtHead(node1, 4);
    insertAtHead(node1, 3);
    insertAtHead(node1, 2);
    insertAtHead(node1, 1);
    // pointing temp to the last element of list:
    Node *temp = node1;
    temp = temp->next->next->next->next->next;
    // connecting temp with second element:
    temp->next = node1->next;

    // detecting the loop with first APPROACH:
    if (detectLoop(node1))
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "not present" << endl;
    }

    // detecting the loop with floyd cycle detection APPROACH:
    if (detectLoopByFloydCycleDetection(node1) != NULL)
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "not present" << endl;
    }

    // finding the starting Node of the loop in LL:
    // we can also achieve this using map vali approach, but we will do this again with two pointers approach, continuation of floyd cycle detection:
    int x = findTheStartOfLoop(node1)->data;
    cout << "The start element of the loop is: " << x << endl;

    // removing the cycle or loop from LL:
    removeLoop(node1);
    if (detectLoop(node1))
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "not present" << endl;
    }

    // delete node1;
}