/*
Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.
In zig zag traversal starting from the first level go from left to right for odd-numbered levels and right to left for even-numbered levels.

Example 1:

Input:
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
Output:
1 3 2 4 5 6 7
Explanation:
For level 1 going left to right, we get traversal as {1}.
For level 2 going right to left, we get traversal as {3,2}.
For level 3 going left to right, we get traversal as {4,5,6,7}.
Merging all this traversals in single array we get {1,3,2,4,5,6,7}
*/

// SOLUTION:
// #include <vector>
// #include <queue>
/*
vector<vector<int>> zigZagTraversal(Node *root)
{
    // vector to store answer:
    vector<vector<int>> ans;

    if (root == NULL)
    {
        return;
    }

    // make a queue to push nodes:
    queue<Node *> q;
    q.push(root);

    // Flag to determine the direction of
    // traversal (left to right or right to left)
    bool leftToRight = true;

    while (!q.empty())
    {

        int size = q.size();

        // Vector to store the values
        // of nodes at the current level
        vector<int> temp(size);

        for (int i = 0; i < size; i++)
        {
            // Get the front node
            // from the queue
            Node *front = q.front();
            q.pop();

            // Determine the index to insert the node's  value based on the traversal direction
            int index = leftToRight ? i : (size - 1 - i);

            temp[index] = front->data;

            // Enqueue the left and right children if they exist
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }

        // Switch the traversal direction for the next level
        leftToRight = !leftToRight;

        // Add the current level's values to the result vector
        ans.push_back(temp);
    }

    return ans;
}
*/
