# Link: https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

from typing import Optional
from collections import deque

from typing import List


class Node:

    def __init__(self, val):
        self.data = val
        self.right = None
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
    def findPaths(self, node, path: List[int], result: List[List[int]]):
        if node is None:
            return

        path.append(node.data)

        if not node.left and not node.right:
            result.append(path[:])
        else:
            self.findPaths(node.left, path, result)
            self.findPaths(node.right, path, result)

        path.pop()

    def Paths(self, root):
        result = []
        self.findPaths(root, [], result)
        return result


if __name__ == "__main__":
    obj = Solution()
    s = "1 2 3 4 5 N N"
    root = buildTree(s)
    result = obj.Paths(root)
    for path in result:
        print(" ".join(map(str, path)))
    print()

    s = "1 2 3"
    root = buildTree(s)
    result = obj.Paths(root)
    for path in result:
        print(" ".join(map(str, path)))
    print()

    s = "10 20 30 40 60 N N"
    root = buildTree(s)
    result = obj.Paths(root)
    for path in result:
        print(" ".join(map(str, path)))
    print()
