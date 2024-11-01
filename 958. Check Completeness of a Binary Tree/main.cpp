#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isCompleteTree(TreeNode *root)
{
    if (!root)
        return true; // An empty tree is complete

    queue<TreeNode *> q;
    q.push(root);
    bool foundNull = false; // Flag to mark the presence of a null node

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (node)
        {
            if (foundNull)
                return false;    // If a non-null node appears after a null node
            q.push(node->left);  // Add left child to the queue
            q.push(node->right); // Add right child to the queue
        }
        else
        {
            foundNull = true; // Set flag on encountering the first null node
        }
    }
    return true; // All nodes were in the correct order, so the tree is complete
}

int main()
{
    // Example: creating a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    // Test
    if (isCompleteTree(root))
        cout << "The tree is complete." << endl;
    else
        cout << "The tree is not complete." << endl;

    return 0;
}
