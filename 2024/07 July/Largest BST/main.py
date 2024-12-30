# Link: https://www.geeksforgeeks.org/problems/largest-bst/1

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

    # Creating list of strings from input string after splitting by space
    ip = list(map(str, s.split()))

    # Create the root of the tree
    root = Node(int(ip[0]))
    size = 0
    q = deque()

    # Push the root to the queue
    q.append(root)
    size += 1

    # Starting from the second element
    i = 1
    while size > 0 and i < len(ip):
        # Get and remove the front of the queue
        currNode = q.popleft()
        size -= 1

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if currVal != "N":
            # Create the left child for the current node
            currNode.left = Node(int(currVal))
            # Push it to the queue
            q.append(currNode.left)
            size += 1

        # Move to the next element
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
            size += 1

        # Move to the next element
        i += 1

    return root


class Solution:
    def check_bst(self, root, low, high):
        if root is None:
            return 1
        val = root.data
        if not (low < val < high):
            return 0
        return self.check_bst(root.right, val, high) * self.check_bst(
            root.left, low, val
        )

    def size(self, root):
        if root is None:
            return 0
        return 1 + self.size(root.right) + self.size(root.left)

    def largestBst(self, root):
        if root is None:
            return 0
        if self.check_bst(root, -100001, 1000001):
            return 1 + self.size(root.left) + self.size(root.right)
        return max(self.largestBst(root.left), self.largestBst(root.right))


if __name__ == "__main__":
    obj = Solution()
    s = "1 4 4 6 8"
    root = buildTree(s)
    print(obj.largestBst(root))

    s = "6 6 2 N 2 1 3"
    root = buildTree(s)
    print(obj.largestBst(root))
