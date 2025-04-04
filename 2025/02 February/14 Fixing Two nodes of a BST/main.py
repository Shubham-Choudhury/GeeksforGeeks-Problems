# Link: https://www.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1

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


def isBST(n, lower, upper):
    if n is None:
        return True
    if n.data <= lower or n.data >= upper:
        return False
    return isBST(n.left, lower, n.data) and isBST(n.right, n.data, upper)


def compare(a, b, mismatch):
    if a is None and b is None:
        return True
    if a is None or b is None:
        return False

    if a.data != b.data:
        mismatch.append((a.data, b.data))

    return compare(a.left, b.left, mismatch) and compare(a.right, b.right, mismatch)


class Solution:
    def correctBST(self, root):
        def inOrder(node):
            nonlocal prev, first, second
            if node is None:
                return
            inOrder(node.left)
            if prev and prev.data > node.data:
                if not first:
                    first = prev
                second = node
            prev = node
            inOrder(node.right)

        prev = None
        first = None
        second = None
        inOrder(root)
        first.data, second.data = second.data, first.data


if __name__ == "__main__":
    obj = Solution()
    s = "10 5 8 2 20"
    root = buildTree(s)
    obj.correctBST(root)

    s = "5 10 20 2 8"
    root = buildTree(s)
    obj.correctBST(root)
