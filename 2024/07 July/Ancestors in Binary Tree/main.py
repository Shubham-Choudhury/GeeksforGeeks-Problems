# Link: https://www.geeksforgeeks.org/problems/ancestors-in-binary-tree/1

import sys

sys.setrecursionlimit(50000)
from collections import deque


# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


"""
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
"""


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
    def __init__(self):
        self.temp = []

    def solve(self, root, target, v):
        if not root:
            return

        if root.data == target:
            self.temp = v.copy()
            return

        v.append(root.data)
        self.solve(root.left, target, v)
        self.solve(root.right, target, v)
        v.pop()

    def Ancestors(self, root, target):
        """
        :param root: root of the given tree.
        :return: None, print the space separated post ancestors of given target., don't print new line
        """
        v = []
        self.solve(root, target, v)
        self.temp.reverse()
        return self.temp


def main():
    obj = Solution()
    s = "1 2 3 4 5 6 8 7"
    root = buildTree(s)
    target = 7
    res = obj.Ancestors(root, target)
    print(" ".join(map(str, res)))

    s = "1 2 3"
    root = buildTree(s)
    target = 1
    res = obj.Ancestors(root, target)
    print(" ".join(map(str, res)))


if __name__ == "__main__":
    main()
