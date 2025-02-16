# Link: https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

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


def inorder(root):
    if not root:
        return
    inorder(root.left)
    print(root.data, end=" ")
    inorder(root.right)


def _deleteTree(node):
    if node == None:
        return

    # first delete both subtrees
    _deleteTree(node.left)
    _deleteTree(node.right)
    node.left = None
    node.right = None
    # then delete the node


# Deletes a tree and sets the root as NULL
def deleteTree(node_ref):
    _deleteTree(node_ref)
    node_ref = None


class Solution:
    def serialize(self, root):
        if not root:
            return []

        result = []
        queue = deque([root])

        while queue:
            node = queue.popleft()
            if node:
                result.append(node.data)
                queue.append(node.left)
                queue.append(node.right)
            else:
                result.append(None)

        return result

    def deSerialize(self, arr):
        if not arr:
            return None

        root = Node(arr[0])
        queue = deque([root])
        i = 1

        while queue and i < len(arr):
            node = queue.popleft()

            if arr[i] is not None:
                node.left = Node(arr[i])
                queue.append(node.left)
            i += 1

            if i < len(arr) and arr[i] is not None:
                node.right = Node(arr[i])
                queue.append(node.right)
            i += 1

        return root


if __name__ == "__main__":
    obj = Solution()
    s = "1 2 3"
    root = buildTree(s)
    inorder(root)
    print()
    arr = obj.serialize(root)
    print(arr)
    root = obj.deSerialize(arr)
    inorder(root)
    print()
    deleteTree(root)
    inorder(root)
    print()
    print("Tree Deleted")
    print()

    s = "10 20 30 40 60 N N"
    root = buildTree(s)
    inorder(root)
    print()
    arr = obj.serialize(root)
    print(arr)
    root = obj.deSerialize(arr)
    inorder(root)
    print()
    deleteTree(root)
    inorder(root)
    print()
    print("Tree Deleted")
    print()
