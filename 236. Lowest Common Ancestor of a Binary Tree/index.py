class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # Base case: if the root is None or root is either p or q, return root
        if not root or root == p or root == q:
            return root

        # Search in left and right subtrees
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)

        # If both left and right are not None, then the current node is the LCA
        if left and right:
            return root

        # Otherwise, return the non-None value (either left or right)
        return left if left else right


def main():
    # Constructing the example tree:
    #         3
    #        / \
    #       5   1
    #      / \ / \
    #     6  2 0  8
    #       / \
    #      7   4
    root = TreeNode(3)
    root.left = TreeNode(5)
    root.right = TreeNode(1)
    root.left.left = TreeNode(6)
    root.left.right = TreeNode(2)
    root.right.left = TreeNode(0)
    root.right.right = TreeNode(8)
    root.left.right.left = TreeNode(7)
    root.left.right.right = TreeNode(4)

    p = root.left       # Node 5
    q = root.right      # Node 1

    # Finding LCA
    solution = Solution()
    lca = solution.lowestCommonAncestor(root, p, q)
    print(f"The Lowest Common Ancestor of nodes {
          p.val} and {q.val} is: {lca.val}")


if __name__ == "__main__":
    main()
