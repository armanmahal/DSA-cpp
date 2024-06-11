// implementation of a binary search tree.

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

// function to print bst
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

// function to search some node:
void searchBST(Node *root, int data)
{

    // RECUSIVE APPROACH:
    /*

    // base cases:
    if (root == NULL)
    {
        cout << "not found" << endl;
        return;
    }
    if (root->data == data)
    {
        cout << "found " << endl;
        return;
    }

    // if data is greater than current node:
    if (data > root->data)
    {
        // search in right part:
        searchBST(root->right, data);
    }
    // if data is smaller than curent node:
    if (data < root->data)
    {
        // search in left part:
        searchBST(root->left, data);
    }

    */

    // ITERATIVE APPROACH:
    while (root != NULL)
    {
        if (root->data == data)
        {
            cout << "found" << endl;
            return;
        }

        // if data is greater than current node:
        if (data > root->data)
        {
            // search in right part:
            root = root->right;
        }
        // if data is smaller than curent node:
        else
        {
            // search in left part:
            root = root->left;
        }
    }
    // if not found:
    cout << "not found" << endl;
    return;
}

// function to find minimum value:
int minBST(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    cout << root->data << endl;
    return root->data;
}

// function to find maximum value:
void maxBST(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    cout << root->data << endl;
}

// function to delete a node:
Node *deleteNodeFromBST(Node *&root, int data)
{
    // base case:
    if (root == NULL)
    {
        return root;
    }
    // if data found:
    if (root->data == data)
    {
        // delete it

        // if 0 child:
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // if 1 child:
        // if left child:
        else if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // if right child:
        else if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // if 2 child (root->left != NULL && root->right != NULL):
        else
        {
            // take the minimum value from right of the node to delete and insert it in place of the node that you need to delete:
            int mini = minBST(root->right);
            // replace the value of the node that you need to delete with this minimum value:
            root->data = mini;

            // now delete this leaf node that had minimum value with recursive call:
            root->right = deleteNodeFromBST(root->right, mini);

            return root;
        }
    }
    // if data smaller , search in left part:
    else if (data < root->data)
    {
        root->left = deleteNodeFromBST(root->left, data);
        return root;
    }
    // if data greater , search in right part:
    else
    {
        root->right = deleteNodeFromBST(root->right, data);
        return root;
    }
}

int main()
{

    Node *root = NULL;

    cout << "Enter data to create BST:" << endl;
    takeInput(root);

    cout << "printing the BST:" << endl;
    levelOrderTraversal(root);

    cout << "Enter the Data to search: ";
    int x;
    cin >> x;
    searchBST(root, x);

    cout << "The min value is: ";
    minBST(root);

    cout << "The max value is: ";
    maxBST(root);

    cout << "Enter element to delete :";
    int y;
    cin >> y;
    root = deleteNodeFromBST(root, y);
    cout << "printing the BST:" << endl;
    levelOrderTraversal(root);
}