// add two numbers represented by two linked lists.

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

void reverse(Node *&head)
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
Node *addTwoNumbers(Node *head1, Node *head2)
{
    // first reverse the lists so as to add them up correctly:
    reverse(head1);
    reverse(head2);

    // now add the two lists and store in a new LL:
    Node *ans = new Node(-1);
    Node *ansTail = ans;
    int carry = 0;
    while (head1 != NULL && head2 != NULL)
    {
        int element1 = head1->data;
        int element2 = head2->data;
        int sum = element1 + element2 + carry;
        carry = sum / 10;
        sum = sum % 10;

        // inserting sum into new LL:
        Node *temp = new Node(sum);
        ansTail->next = temp;
        ansTail = ansTail->next;

        head1 = head1->next;
        head2 = head2->next;
    }

    // if some elements in list1 remains:
    while (head1 != NULL)
    {
        int sum = head1->data + carry;
        carry = sum / 10;
        sum = sum % 10;

        // inserting sum into new LL:
        Node *temp = new Node(sum);
        ansTail->next = temp;
        ansTail = ansTail->next;

        head1 = head1->next;
    }
    // if some elements in list2 remains:
    while (head2 != NULL)
    {
        int sum = head2->data + carry;
        carry = sum / 10;
        sum = sum % 10;

        // inserting sum into new LL:
        Node *temp = new Node(sum);
        ansTail->next = temp;
        ansTail = ansTail->next;

        head2 = head2->next;
    }
    // if carry remains:
    if (carry)
    {
        Node *temp = new Node(carry);
        carry = 0;
        ansTail->next = temp;
        ansTail = ansTail->next;
    }

    // removing the temporary node from ans LL:
    Node *temp = ans;
    ans = ans->next;
    temp->next = NULL;
    delete temp;

    // reversing the answer LL and returning it:
    reverse(ans);
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
    Node *node2 = NULL;
    insertAtHead(node2, 1);
    insertAtHead(node2, 4);
    insertAtHead(node2, 8);
    insertAtHead(node2, 0);
    insertAtHead(node2, 1);
    insertAtHead(node2, 7);

    printLinkedList(node1);
    printLinkedList(node2);

    Node *ans = addTwoNumbers(node1, node2);
    printLinkedList(ans);

    delete node1;
    delete node2;
    delete ans;
}