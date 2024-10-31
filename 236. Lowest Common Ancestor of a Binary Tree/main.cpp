#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // Base case: if the root is null, or we find either p or q, return root
        if (!root || root == p || root == q)
        {
            return root;
        }

        // Recur on the left and right subtrees
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // If both left and right are not null, root is the LCA
        if (left && right)
        {
            return root;
        }

        // Otherwise, return the non-null value
        return left ? left : right;
    }
};

int main()
{
    Solution solution;

    // Constructing the example tree:
    //         3
    //        / \
    //       5   1
    //      / \ / \
    //     6  2 0  8
    //       / \
    //      7   4
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode *p = root->left;  // Node 5
    TreeNode *q = root->right; // Node 1

    TreeNode *lca = solution.lowestCommonAncestor(root, p, q);
    cout << "The Lowest Common Ancestor of nodes " << p->val << " and " << q->val << " is: " << lca->val << endl;

    return 0;
}
