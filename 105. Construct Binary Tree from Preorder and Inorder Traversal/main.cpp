#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // Build a hashmap to store the index of each value in the inorder array
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderIndexMap[inorder[i]] = i;
        }
        // Call the recursive helper function to construct the tree
        return arrayToTree(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

private:
    unordered_map<int, int> inorderIndexMap; // Map to store element indices in inorder traversal

    // Recursive helper function to construct the tree
    TreeNode *arrayToTree(vector<int> &preorder, int preStart, int preEnd, int inStart, int inEnd)
    {
        // Base case: if there are no elements to construct the tree
        if (preStart > preEnd || inStart > inEnd)
        {
            return nullptr;
        }

        // Get the root value from the preorder array
        int rootValue = preorder[preStart];
        TreeNode *root = new TreeNode(rootValue);

        // Find the root index in inorder array
        int inorderIndex = inorderIndexMap[rootValue];

        // Calculate the size of the left subtree
        int leftTreeSize = inorderIndex - inStart;

        // Recursively build the left and right subtrees
        root->left = arrayToTree(preorder, preStart + 1, preStart + leftTreeSize, inStart, inorderIndex - 1);
        root->right = arrayToTree(preorder, preStart + leftTreeSize + 1, preEnd, inorderIndex + 1, inEnd);

        return root;
    }
};

// Function to print inorder traversal for testing the constructed tree
void printInorder(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

int main()
{
    Solution solution;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *root = solution.buildTree(preorder, inorder);

    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
