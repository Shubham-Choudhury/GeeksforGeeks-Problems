# Link: https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

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
    q = deque()

    # Push the root to the queue
    q.append(root)

    # Starting from the second element
    i = 1
    while len(q) > 0 and i < len(ip):
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
    def LCA(self, root, n1, n2):
        if not root:
            return None
        if root.data > n1.data and root.data > n2.data:
            return self.LCA(root.left, n1, n2)
        elif root.data < n1.data and root.data < n2.data:
            return self.LCA(root.right, n1, n2)
        else:
            return root


if __name__ == "__main__":
    object = Solution()
    s = "5 4 6 3 N N 7 N N N 8"
    n1 = 7
    n2 = 8
    root = buildTree(s)
    node1 = Node(n1)
    node2 = Node(n2)
    ans = object.LCA(root, node1, node2)
    print(ans.data)

    s = "20 8 22 4 12 N N N N 10 14"
    n1 = 8
    n2 = 14
    root = buildTree(s)
    node1 = Node(n1)
    node2 = Node(n2)
    ans = object.LCA(root, node1, node2)
    print(ans.data)

    s = "2 1 3"
    n1 = 1
    n2 = 3
    root = buildTree(s)
    node1 = Node(n1)
    node2 = Node(n2)
    ans = object.LCA(root, node1, node2)
    print(ans.data)
