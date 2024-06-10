/*
Check if a given Binary Tree is Sum Tree

Write a function that returns true if the given Binary Tree is SumTree else false. A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is SumTree and the sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.

Following is an example of SumTree.

          26
        /   \
      10     3
    /    \     \
  4      6      3

*/

// #include <pair>
/*
pair<bool, int> isSumTree(Node *root)
{
    // base cases:
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    // if leaf node:
    if (root->next == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    // recursive call for left part:
    pair<bool, int> left = isSumTree(root->left);
    // recursive call for right part:
    pair<bool, int> right = isSumTree(root->right);

    // checking the current node :
    bool current = (root->data) == (left.second + right.second);

    // returning the ans:
    pair<bool, int> ans;
    ans.second = left.second + right.second + root->data;
    if (left.first && right.first && current)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

*/
