// find the k'th smallest element is a given BST.

// SOLUTION:
#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
// function to insert node to bst:
Node *insertToBST(Node *&root, int data)
{
    // if root is NULL:
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    // if data is greater than root:
    if (data > root->data)
    {
        root->right = insertToBST(root->right, data);
    }
    // if data is smaller than root:
    else
    {
        root->left = insertToBST(root->left, data);
    }

    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertToBST(root, data);
        cin >> data;
    }
}

// function to find k'th smallest element:
void solve(Node *root, int k, int &i)
{
    // basecase
    if (root == NULL)
    {
        return;
    }

    // going to left:
    solve(root->left, k, i);
    // coming back to the current node:
    i++;
    if (k == i)
    {
        cout << root->data << endl;
        return;
    }
    // going to right:
    solve(root->right, k, i);
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST:" << endl;
    takeInput(root);

    int k = 3;
    int index = 0;
    cout << "the " << k << "'th smallest element is: ";
    solve(root, k, index);
}