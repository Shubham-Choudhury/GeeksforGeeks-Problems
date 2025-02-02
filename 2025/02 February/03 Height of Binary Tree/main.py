# Link: https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

from collections import deque


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
    def height(self, root):
        if root is None:
            return 0

        q = [root]
        height = 0

        while q:
            level_size = len(q)
            for _ in range(level_size):
                current = q.pop(0)
                if current.left:
                    q.append(current.left)
                if current.right:
                    q.append(current.right)

            height += 1

        return height - 1 if height else height


if __name__ == "__main__":
    object = Solution()
    s = "12 5 18 8 11"
    root = buildTree(s)
    height = object.height(root)
    print("Height of the tree is:", height)

    s = "1 2 3 4 N N 5 N N 6 7"
    root = buildTree(s)
    height = object.height(root)
    print("Height of the tree is:", height)
