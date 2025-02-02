# Link: https://www.geeksforgeeks.org/problems/level-order-traversal/1

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
    def levelOrder(self, root):
        vt = []
        if not root:
            return vt

        q = [root]
        while q:
            n = len(q)
            sol = []

            for _ in range(n):
                tmp = q.pop(0)
                if tmp.left is not None:
                    q.append(tmp.left)
                if tmp.right is not None:
                    q.append(tmp.right)
                sol.append(tmp.data)
            vt.append(sol)
        return vt


if __name__ == "__main__":
    obj = Solution()
    s = "1 2 3"
    root = buildTree(s)
    res = obj.levelOrder(root)
    for i in res:
        print(i, end=" ")
    print()

    s = "10 20 30 40 50"
    root = buildTree(s)
    res = obj.levelOrder(root)
    for i in res:
        print(i, end=" ")
    print()

    s = "1 3 2 N N N 4 6 5"
    root = buildTree(s)
    res = obj.levelOrder(root)
    for i in res:
        print(i, end=" ")
    print()
