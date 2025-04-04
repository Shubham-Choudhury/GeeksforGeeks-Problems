# Link: https://www.geeksforgeeks.org/problems/k-distance-from-root/1

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
    def KDistance(self, root, k):
        queue = []
        ans = []

        count = 0
        queue.append(root)
        while queue and count <= k + 1:
            level = []
            for i in range(len(queue)):
                node = queue.pop(0)
                if node:
                    level.append(node.data)
                    queue.append(node.left)
                    queue.append(node.right)

            if level:
                ans.append(level)
                count += 1

        return ans[k] if len(ans) > k else []


if __name__ == "__main__":
    obj = Solution()
    values = "1 3 2"
    root = buildTree(values)
    k = 0
    print(obj.KDistance(root, k))

    values = "1 2 1 5 3"
    root = buildTree(values)
    k = 3
    print(obj.KDistance(root, k))
