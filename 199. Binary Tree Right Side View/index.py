# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def preOrder(self, root, level, result):
        if root is None:
            return

        # Check if this level is being visited for the first time
        if len(result) < level:
            result.append(root.val)

        # Traverse the right subtree first
        self.preOrder(root.right, level + 1, result)
        # Then traverse the left subtree
        self.preOrder(root.left, level + 1, result)

    def rightSideView(self, root):
        result = []
        self.preOrder(root, 1, result)  # Start from level 1
        return result


# Example usage:
if __name__ == "__main__":
    # Create a sample binary tree:
    #        1
    #       / \
    #      2   3
    #       \   \
    #        5   4
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.right = TreeNode(5)
    root.right.right = TreeNode(4)

    solution = Solution()
    right_view = solution.rightSideView(root)
    print(right_view)  # Output: [1, 3, 4]
