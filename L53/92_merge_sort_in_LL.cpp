// sort a LL with merge sort:

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

void insertAtHead(Node *&head, int dataue)
{
    if (head == NULL)
    {
        Node *newNode = new Node(dataue);
        head = newNode;
        return;
    }
    else
    {
        Node *newNode = new Node(dataue);
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
// merge sort:
Node *sort(Node *head)
{
    // base case if size of list becomes zero or one:
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // now find the mid of list to divide it into two halves:
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    Node *middle = slow;
    // dividing the LL into two LLs:
    Node *leftList = head;
    Node *rightList = middle->next;
    middle->next = NULL;

    // recursive call to sort the divided halves of LL:
    Node *sortedLeft = sort(leftList);
    Node *sortedRight = sort(rightList);

    // now merge the two sorted halves:
    Node *ans = mergeLists(sortedLeft, sortedRight);

    // returning the final sorted LL:
    return ans;
}

int main()
{
    Node *node1 = NULL;
    insertAtHead(node1, 1);
    insertAtHead(node1, 4);
    insertAtHead(node1, 5);
    insertAtHead(node1, 6);
    insertAtHead(node1, 2);
    insertAtHead(node1, 9);
    insertAtHead(node1, 9);

    printLinkedList(node1);

    Node *sortedList = sort(node1);

    printLinkedList(sortedList);

    delete sortedList;
}