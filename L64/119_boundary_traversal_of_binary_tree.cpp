/*
Boundary Traversal of a Binary Tree

Problem Statement: Given a Binary Tree, perform the boundary traversal of the tree. The boundary traversal is the process of visiting the boundary nodes of the binary tree in the anticlockwise direction, starting from the root.
*/

// SOLUTION:

/*
void traverseLeft(Node *root, vector<int> &ans)
{
    // base cases:
    if (root == NULL)
    {
        return;
    }
    // if leaf node:
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    ans.push_back(root->data);

    // recursive call:
    if (root->left != NULL)
    {
        traverseLeft(root->left, ans);
    }
    else
    {
        traverseLeft(root->right, ans);
    }
}
void traverseLeaf(Node *root, vector<int> &ans)
{
    // base case:
    if (root == NULL)
    {
        return;
    }
    // if leaf node:
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    // recurive call for left and right:
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}
void traverseRight(Node *root, vector<int> &ans)
{
    // base cases:
    if (root == NULL)
    {
        return;
    }
    // if leaf node:
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    // recurive call for right :
    if (root->right != NULL)
    {
        traverseRight(root->right, ans);
    }
    else
    {
        traverseRight(root->left, ans);
    }

    // storing the data to current node (in reverse order because this is stored after the recursive call):
    ans.push_back(root->data);
}
vector<int> boundaryTraversal(Node *root)
{
    // create a vector to store elements:
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    ans.push_back(root->data);

    // traversing the left part:
    traverseLeft(root->left, ans);
    // traversing the leaf nodes:
    traverseLeaf(root, ans);
    // traversing the right part:
    traverseRight(root->right, ans);

    // returning the ans:
    return ans;
}
*/

