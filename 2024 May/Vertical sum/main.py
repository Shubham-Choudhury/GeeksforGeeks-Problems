# Link: https://www.geeksforgeeks.org/problems/vertical-sum/1

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
    def verticalSum(self, root):
        q = deque()
        q.append([root, 0])
        d = dict()
        xl, xr = 9999999, 0
        while len(q) > 0:
            curr = q.popleft()
            xl = min(xl, curr[1])
            xr = max(xr, curr[1])
            d[curr[1]] = d.get(curr[1], 0) + curr[0].data
            if curr[0].left != None:
                q.append([curr[0].left, curr[1] - 1])
            if curr[0].right != None:
                q.append([curr[0].right, curr[1] + 1])
        ans = []
        for x in range(xl, xr + 1):
            ans.append(d[x])
        return ans


if __name__ == "__main__":
    obj = Solution()
    s = "1 2 3 4 5 6 7"
    root = buildTree(s)
    print(obj.verticalSum(root))
