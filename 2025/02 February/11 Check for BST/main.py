# Link: https://www.geeksforgeeks.org/problems/check-for-bst/1

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
    def is_bst(self, root):
        in_order = []
        self.inorder(root, in_order)

        for i in range(1, len(in_order)):
            if in_order[i - 1] > in_order[i]:
                return False

        return True

    def inorder(self, root, v):
        if root is None:
            return
        self.inorder(root.left, v)
        v.append(root.data)
        self.inorder(root.right, v)


if __name__ == "__main__":
    obj = Solution()
    s = "2 1 3 N N N 5"
    root = buildTree(s)
    print(obj.is_bst(root))

    s = "2 N 7 N 6 N 9"
    root = buildTree(s)
    print(obj.is_bst(root))

    s = "10 5 20 N N 9 25"
    root = buildTree(s)
    print(obj.is_bst(root))
