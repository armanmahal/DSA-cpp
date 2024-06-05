// given a linked list , check if it is palindrome or not. (two approaches)

#include <iostream>
#include <vector>
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

// APPROACH 1: copy LL into a vector and then check palindrome using two pointer approach
void checkPalindromeUsingVector(Node *&head)
{

    // copying list into a vector:
    vector<int> vec;
    Node *temp = head;
    while (temp != NULL)
    {
        vec.push_back(temp->data);
        temp = temp->next;
    }

    // checking palindrome for that vector:
    int s = 0;
    int e = vec.size() - 1;
    while (s <= e)
    {
        if (vec[s] != vec[e])
        {
            cout << "not a palindrome" << endl;
            return;
        }
        s++;
        e--;
    }

    // if out of loop then it means it is palindrome:
    cout << "palindrome" << endl;
}

// APPROACH 2: reverse a linked list from the middle of it and have two pointers one at start and one at middle to compare the elements:
void checkPalindromeByMiddle(Node *head)
{
    // finding the middle:
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    Node *middle = slow->next;

    //disconnecting list from middle from rest of the LL:
    slow->next = NULL;

    // reversing list from middle:
    Node *previous = NULL;
    Node *current = middle;
    while (current != NULL)
    {
        middle = middle->next;
        current->next = previous;
        previous = current;
        current = middle;
    }
    middle = previous;

    //now compare the list from head and from middle:
    while(middle!=NULL){
        if(head->data != middle->data){
            cout<<"not a palindrome"<<endl;
            return;
        }
        head = head->next;
        middle = middle->next;
    }
    // if out of loop then it means it is palindrome:
    cout << "palindrome" << endl;
}

int main()
{
    Node *node1 = NULL;
    insertAtHead(node1, 1);
    insertAtHead(node1, 1);
    insertAtHead(node1, 2);
    insertAtHead(node1, 0);
    insertAtHead(node1, 2);
    insertAtHead(node1, 1);
    insertAtHead(node1, 1);
    Node *node2 = NULL;
    insertAtHead(node2, 1);
    insertAtHead(node2, 1);
    insertAtHead(node2, 2);
    insertAtHead(node2, 0);
    insertAtHead(node2, 1);
    insertAtHead(node2, 1);

    printLinkedList(node1);
    checkPalindromeUsingVector(node1);
    checkPalindromeByMiddle(node1);

    printLinkedList(node2);
    checkPalindromeUsingVector(node2);
    checkPalindromeByMiddle(node2);

    delete node1;
    delete node2;
}