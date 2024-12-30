# Link: https://www.geeksforgeeks.org/problems/root-to-leaf-paths-sum/1

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
    #   print(ip)
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
    def treePathSum(self, root):
        if not root:
            return 0

        total_sum = 0
        stack = [(root, 0)]

        while stack:
            node, path_sum = stack.pop()
            path_sum = path_sum * 10 + node.data

            if not node.left and not node.right:
                total_sum += path_sum
            else:
                if node.right:
                    stack.append((node.right, path_sum))
                if node.left:
                    stack.append((node.left, path_sum))

        return total_sum


if __name__ == "__main__":
    object = Solution()
    s = "6 3 5 2 5 N 4 N N 7 4 N N"
    root = buildTree(s)
    print(object.treePathSum(root))

    s = "10 20 30 40 60 N N"
    root = buildTree(s)
    print(object.treePathSum(root))
