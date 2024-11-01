from collections import deque

# Definition for a binary tree node.


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def isCompleteTree(root):
    if not root:  # An empty tree is considered complete
        return True

    queue = deque([root])
    found_null = False  # Flag to indicate if a null node has been encountered

    while queue:
        node = queue.popleft()

        if node:
            if found_null:
                return False  # If a non-null node appears after a null, the tree isn't complete
            queue.append(node.left)
            queue.append(node.right)
        else:
            found_null = True  # Mark the first null encounter

    return True  # All nodes were in the correct order, so the tree is complete

# Main function to test the completeness of a binary tree


def main():
    # Example 1: Complete binary tree
    root1 = TreeNode(1)
    root1.left = TreeNode(2)
    root1.right = TreeNode(3)
    root1.left.left = TreeNode(4)
    root1.left.right = TreeNode(5)
    root1.right.left = TreeNode(6)

    # Example 2: Incomplete binary tree
    root2 = TreeNode(1)
    root2.left = TreeNode(2)
    root2.right = TreeNode(3)
    root2.left.left = TreeNode(4)
    root2.left.right = TreeNode(5)
    root2.right.right = TreeNode(7)  # Node 7 isn't as far left as possible

    # Test cases
    print("Tree 1 is complete:", isCompleteTree(root1))  # Expected output: True
    # Expected output: False
    print("Tree 2 is complete:", isCompleteTree(root2))


if __name__ == "__main__":
    main()
