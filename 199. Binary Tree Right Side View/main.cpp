#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void preOrder(TreeNode *root, int level, vector<int> &result)
    {
        if (root == nullptr)
        {
            return;
        }

        // Check if this level is being visited for the first time
        if (result.size() < level)
        {
            result.push_back(root->val);
        }

        // Traverse the right subtree first
        preOrder(root->right, level + 1, result);
        // Then traverse the left subtree
        preOrder(root->left, level + 1, result);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        preOrder(root, 1, result); // Start from level 1
        return result;
    }
};

// Example usage:
int main()
{
    // Create a sample binary tree:
    //        1
    //       / \
    //      2   3
    //       \   \
    //        5   4
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution solution;
    vector<int> right_view = solution.rightSideView(root);

    // Print the right-side view
    cout << "Right Side View: ";
    for (int val : right_view)
    {
        cout << val << " ";
    }
    cout << endl;

    // Free allocated memory (clean-up)
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}

// Time Complexity: O(n), where n is the number of nodes in the tree. Each node is visited exactly once.
// Space Complexity: O(h), where h is the height of the tree. This space is used for the recursion stack.