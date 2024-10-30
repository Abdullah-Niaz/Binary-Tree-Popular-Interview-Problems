# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, preorder, inorder):
        # Create a hashmap to store the index of elements in the inorder list
        inorder_index_map = {value: index for index,
                             value in enumerate(inorder)}

        # Helper function to build the tree recursively
        def array_to_tree(left, right):
            nonlocal preorder_index
            # Base case: If there are no elements to construct the tree
            if left > right:
                return None

            # Get the root value and increment preorder index
            root_value = preorder[preorder_index]
            preorder_index += 1

            # Create the root node
            root = TreeNode(root_value)

            # Root splits inorder list into left and right subtrees
            inorder_index = inorder_index_map[root_value]

            # Recursively build the left and right subtree
            root.left = array_to_tree(left, inorder_index - 1)
            root.right = array_to_tree(inorder_index + 1, right)

            return root

        # Initialize preorder index and call the recursive helper function
        preorder_index = 0
        return array_to_tree(0, len(inorder) - 1)

# Function to print inorder traversal for testing the constructed tree


def print_inorder(node):
    if node is None:
        return
    print_inorder(node.left)
    print(node.val, end=" ")
    print_inorder(node.right)

# Main function to test the solution


def main():
    # Test data
    preorder = [3, 9, 20, 15, 7]
    inorder = [9, 3, 15, 20, 7]

    # Initialize Solution and build tree
    solution = Solution()
    root = solution.buildTree(preorder, inorder)

    # Print inorder traversal of the constructed tree
    print("Inorder traversal of the constructed tree:")
    print_inorder(root)
    print()


# Run main function
if __name__ == "__main__":
    main()
