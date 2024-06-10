/*
Given a binary tree, find if it is height balanced or not.
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree.

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /
   10
  /
5
*/

// APPROACH ONE:
// recursive function to find height:
/*
int height(Node *root)
{
    // base case:
    if (root == NULL)
    {
        return 0;
    }

    // finding height of left part of root:
    int h1 = height(root->left);
    // finding height of right part of root:
    int h2 = height(root->right);

    // returning the height from current node:
    int ans = max(h1, h2) + 1;
    return ans;
}
*/
// recursive function to check balanced:
/*
bool isBalanced(Node *root)
{
    // base case:
    if (root == NULL)
    {
        return true;
    }

    // check its left node:
    bool left = isBalanced(root->left);
    // check its right node:
    bool right = isBalanced(root->right);

    // check the current node if it is balanced:
    bool current = abs(height(root->left) - height(root->right)) <= 1;

    // returning the ans:
    if (left && right && current)
    {
        return true;
    }
    else
    {
        return false;
    }
}
*/

// APPROACH TWO (optimized - without height function) :

// #include <pair>
/*
pair<bool, int> isBalancedOptimized(Node *root)
{
    // base case:
    if (root == NULL)
    {
        // return balanced as true and height as 0:
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    // recusive call for left node:
    pair<bool, int> left = isBalancedOptimized(root->left);
    // recusive call for right node:
    pair<bool, int> right = isBalancedOptimized(root->right);

    // check the current node if it is balanced:
    bool current = abs(left.second - right.second) <= 1;

    // returning ans:
    if (left.first && right.first && current)
    {
        pair<bool, int> ans = make_pair(true, max(left.second, right.second) + 1);
        return ans;
    }
    else
    {
        pair<bool, int> ans = make_pair(false, max(left.second, right.second) + 1);
        return ans;
    }
}
*/
