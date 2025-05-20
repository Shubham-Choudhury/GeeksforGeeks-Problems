# Link: https://www.geeksforgeeks.org/problems/burning-tree/1

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
    def maxDepth(self, n):
        if n is None:
            return 0
        return 1 + max((self.maxDepth(n.left), self.maxDepth(n.right)))

    def traverse(self, n, target):
        if n is None:
            return (0, 0)

        if n.data == target:
            ans = self.maxDepth(n.right)
            ans = max(ans, self.maxDepth(n.left))
            return (ans, 1)

        ans, dist = self.traverse(n.left, target)
        if dist:
            ans = max(ans, dist + self.maxDepth(n.right))
            return (ans, dist + 1)

        ans, dist = self.traverse(n.right, target)
        if dist:
            ans = max(ans, dist + self.maxDepth(n.left))
            return (ans, dist + 1)

        return (0, 0)

    def minTime(self, root, target):
        return (self.traverse(root, target))[0]


if __name__ == "__main__":
    obj = Solution()
    s = "1 2 3 4 5 6 7"
    target = 2
    root = buildTree(s)
    print(obj.minTime(root, target))

    s = "1 2 3 4 5 N 7 8 N 10"
    target = 10
    root = buildTree(s)
    print(obj.minTime(root, target))
