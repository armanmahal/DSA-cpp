/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/
#include <iostream>
using namespace std;
// SOLUTION:

/*
bool solve(Node *root, int min = INT_MIN, int max = INT_MAX)
{
    // base case :
    if (root == NULL)
    {
        return true;
    }

    if (root->data >= min && root->data <= max)
    {
        // call for left:
        bool left = solve(root->left, min, root->data);
        // call for right:
        bool right = solve(root->right, root->data, max);

        return left && right;
    }
    else
    {
        return false;
    }
}
*/
