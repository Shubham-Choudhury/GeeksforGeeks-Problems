# Link: https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1

from collections import deque


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

    # Creating list of strings from input string after splitting by space
    ip = list(map(str, s.split()))

    # Create the root of the tree
    root = Node(int(ip[0]))
    q = deque()

    # Push the root to the queue
    q.append(root)

    # Starting from the second element
    i = 1
    while q and i < len(ip):
        # Get and remove the front of the queue
        currNode = q.popleft()

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if currVal != "N":
            # Create the left child for the current node
            currNode.left = Node(int(currVal))
            # Push it to the queue
            q.append(currNode.left)

        # For the right child
        i += 1
        if i >= len(ip):
            break
        currVal = ip[i]

        # If the right child is not null
        if currVal != "N":
            # Create the right child for the current node
            currNode.right = Node(int(currVal))
            # Push it to the queue
            q.append(currNode.right)

        i += 1
    return root


class Solution:
    def height(self, node):
        if node is None:
            return 0
        leftHeight = self.height(node.left)
        rightHeight = self.height(node.right)
        return max(leftHeight, rightHeight) + 1

    def findSpiral(self, root):
        res = []
        h = self.height(root)
        ltr = False
        for i in range(1, h + 1):
            self.getLevel(root, i, ltr, res)
            ltr = not ltr
        return res

    def getLevel(self, root, level, ltr, res):
        if root is None:
            return
        if level == 1:
            res.append(root.data)
        elif level > 1:
            if ltr:
                self.getLevel(root.left, level - 1, ltr, res)
                self.getLevel(root.right, level - 1, ltr, res)
            else:
                self.getLevel(root.right, level - 1, ltr, res)
                self.getLevel(root.left, level - 1, ltr, res)


if __name__ == "__main__":
    obj = Solution()
    s = "1 3 2"
    root = buildTree(s)
    ans = obj.findSpiral(root)
    print(*ans)

    s = "10 20 30 40 60"
    root = buildTree(s)
    ans = obj.findSpiral(root)
    print(*ans)

    s = "1 2 N 3"
    root = buildTree(s)
    ans = obj.findSpiral(root)
    print(*ans)
