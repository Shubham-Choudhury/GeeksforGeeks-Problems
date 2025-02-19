# Link: https://www.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1

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
    def findTarget(self, root, target):
        l = []

        def inorder(root):
            if root:
                inorder(root.left)
                l.append(root.data)
                inorder(root.right)

        inorder(root)
        start = 0
        end = len(l) - 1
        while start < end:
            if l[start] + l[end] == target:
                return True
            elif l[start] + l[end] < target:
                start += 1
            else:
                end -= 1
        return False


if __name__ == "__main__":
    obj = Solution()
    s = "7 3 8 2 4 N 9"
    root = buildTree(s)
    target = 12
    print(obj.findTarget(root, target))

    s = "9 5 10 2 6 N 12"
    root = buildTree(s)
    target = 23
    print(obj.findTarget(root, target))
