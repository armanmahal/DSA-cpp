// given a binary tree, find the number of leaf nodes in it:

// function to find number of leaf nodes:

// using inorder traversal to traverse the tree , and find the number of leaf nodes,
//  we can use any method of traversal.

/*
void solve(Node *root, int count = 0)
{
    // base case:
    if (root == NULL)
    {
        return;
    }

    // going to left:
    solve(root->left, count);

    // increasing count if leaf node:
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }

    // going to right:
    solve(root->right, count);
}
*/
