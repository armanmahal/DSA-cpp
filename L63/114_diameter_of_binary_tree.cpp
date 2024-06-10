// finding the diameter of a binary tree, i.e. the longest path that exists in the tree between any two nodes:

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
    int h1 = solve(root->left);
    // finding height of right part of root:
    int h2 = solve(root->right);

    // returning the height from current node:
    int ans = max(h1, h2) + 1;
    return ans;
}
*/

// #APPROACH ONE:
//  recursive function to find diameter:
/*
int diameter(Node *root)
{
    // base case:
    if (root == NULL)
    {
        return 0;
    }

    // three cases of having the longest diameter:

    // 1. if longest path is to the left of root node:
    int d1 = diameter(root->left);
    // 2. if longest path is to the right of root node:
    int d2 = diameter(root->right);
    // 3. if longest path include the root node:
    int d3 = height(root->left) + height(root->right) + 1;

    // the ans would be the maximum of these three cases:
    int ans = max(d1, max(d2 ,d3));
    return ans;
}
*/

// #APPROACH TWO ( optimized - without height function):
// #include <pair>
/*
pair<int, int> diameterOptimized(Node *root)
{

    // base case:
    if (root == NULL)
    {
        // make a pair 'p' , p.first represent diameter, p.second represent height.
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    // recursive call to find height and diameter of left of node:
    pair<int, int> left = diameterOptimized(root->left);
    // recursive call to find height and diameter of right of node:
    pair<int, int> right = diameterOptimized(root->right);

    // diameter of left:
    int d1 = left.first;
    // diameter of right:
    int d2 = right.first;
    // if the longest path includes root node:
    int d3 = left.second + left.second + 1; // i.e height of left + height of right + 1 for root node.

    // returning the ans, i.e the max diameter and max height:
    pair<int,int> ans;
    ans.first = max(d1,max(d2, d3));
    ans.second = max(left.second, right.second)
    return ans;
}

*/
