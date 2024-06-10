// given two trees , check if they are identical or not.

// RECURSIVE FUNCTION TO CHECK IF IDENTICAL:

/*
bool isIdentical(Node *root1, Node *root2)
{

    // base cases:
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL && root2 != NULL)
    {
        return false;
    }
    if (root1 != NULL && root2 == NULL)
    {
        return false;
    }

    // compare the left nodes:
    bool left = isIdentical(root2->left, root2->left);
    // compare the right nodes:
    bool right = isIdentical(root2->right, root2->right);
    // compare the current nodes:
    bool current = root1->data == root2->data;

    // returning ans:
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

