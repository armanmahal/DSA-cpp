// implementation of binary tree
// and different types of traversal of binary tree:
// 1. Level order traversal 2.In order traversal
// 3. pre Order traversal 4. post order traversal

#include <iostream>
#include <queue>
using namespace std;

// class to define a node of binary tree:
class Node
{
private:
public:
    // it has one variable for data
    int data;
    // two pointers to point to next two nodes:
    Node *left;
    Node *right;

    // constructor:
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// recursive function to BUILD THE BINARY TREE:
Node *buildTree(Node *root)
{
    cout << "Enter data to insert (-1 to end) : ";
    int data;
    cin >> data;
    root = new Node(data);

    // base case:
    if (data == -1)
    {
        return NULL;
    }

    // recursive call to create the left node for current node:
    cout << "Enter data to insert in left of " << data << ". " << endl;
    root->left = buildTree(root->left);
    // recursive call to create the right node for current node:
    cout << "Enter data to insert in right of " << data << ". " << endl;
    root->right = buildTree(root->right);

    return root;
}

// LEVEL ORDER TRAVERSAL OF BINARY TREE (use a queue):
// printing the binary tree in level order of traversal:
void levelOrderTraversal(Node *root)
{
    // make a queue to store Nodes:
    queue<Node *> q;
    // inserting the root to the queue:
    q.push(root);
    // inserting NULL to the queue after each level is completely done to maintain intendation:
    q.push(NULL);

    // while queue does not become empty initialize a loop:
    while (!q.empty())
    {
        // storing the current front Node:
        Node *temp = q.front();
        // removing the current front node of queue:
        q.pop();

        // if a level is complete i.e. if a NULL comes in queue, then print in new line:
        if (temp == NULL)
        {
            cout << endl;
            // and if there are still some elements in queue, add a new NULL to the end of queue , as a new level is going to start that will last till this NULL:
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        // if not a NULL:
        else
        {
            // print the data of current front Node of queue:
            cout << temp->data << " ";

            // add the left and right nodes of the current node to the back of queue:
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
    cout << endl;
}

// IN ORDER TRAVERSAL OF BINARY TREE:
void inOrderTraversal(Node *root)
{
    // base case:
    if (root == NULL)
    {
        return;
    }

    // going to the left of node:
    inOrderTraversal(root->left);
    // printing the node while coming back from left:
    cout << root->data << " ";
    // going to the right of node:
    inOrderTraversal(root->right);
}

// IN PREORDER TRAVERSAL OF BINARY TREE:
void preOrderTraversal(Node *root)
{
    // base case:
    if (root == NULL)
    {
        return;
    }

    // printing the node:
    cout << root->data << " ";
    // going to left of node:
    preOrderTraversal(root->left);
    // going to right of node:
    preOrderTraversal(root->right);
}

// IN POSTORDER TRAVERSAL OF BINARY TREE:
void postOrderTraversal(Node *root)
{
    // base case:
    if (root == NULL)
    {
        return;
    }

    // going to left of node:
    postOrderTraversal(root->left);
    // going to right of node:
    postOrderTraversal(root->right);
    // printing the node:
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);

    cout
        << endl
        << endl
        << "Level order traversal: " << endl;
    levelOrderTraversal(root);

    cout << "In Order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Pre Order Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Post Order Traversal: ";
    postOrderTraversal(root);
    cout << endl;
}