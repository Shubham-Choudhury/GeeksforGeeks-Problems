# Link: https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1

from collections import deque


# Tree Node
class Node:

    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


# Function to Build Tree
def buildTree(s):
    # Corner Case
    if len(s) == 0 or s[0] == "N":
        return None

    # Creating list of strings from input
    # string after spliting by space
    ip = list(map(str, s.split()))

    # Create the root of the tree
    root = Node(int(ip[0]))
    size = 0
    q = deque()

    # Push the root to the queue
    q.append(root)
    size = size + 1

    # Starting from the second element
    i = 1
    while size > 0 and i < len(ip):
        # Get and remove the front of the queue
        currNode = q[0]
        q.popleft()
        size = size - 1

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if currVal != "N":

            # Create the left child for the current node
            currNode.left = Node(int(currVal))

            # Push it to the queue
            q.append(currNode.left)
            size = size + 1
        # For the right child
        i = i + 1
        if i >= len(ip):
            break
        currVal = ip[i]

        # If the right child is not null
        if currVal != "N":

            # Create the right child for the current node
            currNode.right = Node(int(currVal))

            # Push it to the queue
            q.append(currNode.right)
            size = size + 1
        i = i + 1
    return root


class Solution:
    def isHeap(self, root):
        if not root:
            return True

        n = self.count_nodes(root)
        return self.is_complete(root, 0, n) and self.is_max_heap_property(root)

    def count_nodes(self, root):
        if not root:
            return 0
        return 1 + self.count_nodes(root.left) + self.count_nodes(root.right)

    def is_complete(self, root, index, n):
        if not root:
            return True
        if index >= n:
            return False
        return self.is_complete(root.left, 2 * index + 1, n) and self.is_complete(
            root.right, 2 * index + 2, n
        )

    def is_max_heap_property(self, root):
        if not root:
            return True
        if root.left and root.data < root.left.data:
            return False
        if root.right and root.data < root.right.data:
            return False
        return self.is_max_heap_property(root.left) and self.is_max_heap_property(
            root.right
        )


if __name__ == "__main__":
    obj = Solution()
    s = "97 46 37 12 3 7 31 6 9"
    root = buildTree(s)
    if obj.isHeap(root):
        print("The given binary tree is a heap.")
    else:
        print("The given binary tree is not a heap.")

    s = "97 46 37 12 3 7 31 N 2 4"
    root = buildTree(s)
    if obj.isHeap(root):
        print("The given binary tree is a heap.")
    else:
        print("The given binary tree is not a heap.")
