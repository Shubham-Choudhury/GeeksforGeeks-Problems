# Link: https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1


class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


class Solution:
    def flattenBST(self, root):
        def flatten(node):
            if node.left:
                first_node, left_last_node = flatten(node.left)
                left_last_node.right = node
                node.left = None
            else:
                first_node = node
            if node.right:
                right_first_node, last_node = flatten(node.right)
                node.right = right_first_node
            else:
                last_node = node
            return first_node, last_node

        return flatten(root)[0]


if __name__ == "__main__":
    root = Node(5)
    root.left = Node(3)
    root.right = Node(7)
    root.left.left = Node(2)
    root.left.right = Node(4)
    root.right.left = Node(6)
    root.right.right = Node(8)
    sol = Solution()
    sol.flattenBST(root)
    while root:
        print(root.data, end=" ")
        root = root.right
    print()
