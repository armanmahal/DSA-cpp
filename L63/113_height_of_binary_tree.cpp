// given a binary tree find its height;

// recursive function to find height:
/*
int solve(Node *root)
{
    // base case:
    if (root == NULL)
    {
        return 0;
    }

    // finding height of left part of root:
    int h1 = solve(root->left);
    // finding height of right part of root:
    int h2 = solve(root->right);

    // returning the height from current node:
    int ans = max(h1, h2) + 1;
    return ans;
}
*/
