# Link: https://www.geeksforgeeks.org/problems/mirror-tree/1

from collections import deque


# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


def inorderTraversalUtil(root):
    # Code here
    if root is None:
        return
    inorderTraversalUtil(root.left)
    print(root.data, end=" ")
    inorderTraversalUtil(root.right)


def inorderTraversal(root):
    # Code here
    inorderTraversalUtil(root)
    print()


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
    def mirror(self, root):
        if not root:
            return

        queue = deque([root])

        while queue:
            current = queue.popleft()
            current.left, current.right = current.right, current.left

            if current.left:
                queue.append(current.left)

            if current.right:
                queue.append(current.right)


if __name__ == "__main__":
    obj = Solution()
    s = "1 2 3"
    node = buildTree(s)
    obj.mirror(node)
    inorderTraversal(node)
    print()
    s = "10 20 30 40 60"
    node = buildTree(s)
    obj.mirror(node)
    inorderTraversal(node)
