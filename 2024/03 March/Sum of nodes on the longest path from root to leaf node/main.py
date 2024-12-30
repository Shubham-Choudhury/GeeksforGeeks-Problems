# Link: https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

from collections import deque


class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


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
    def sumOfLongRootToLeafPath(self, root):
        def dfs(node):
            if node is None:
                return (0, 0)
            max_depth, max_sum = max(dfs(node.left), dfs(node.right))
            return (max_depth + 1, max_sum + node.data)

        return dfs(root)[1]

if __name__=="__main__":
    obj = Solution()
    root = buildTree("4 2 5 7 1 2 3 N N 6")
    print(obj.sumOfLongRootToLeafPath(root))