# Link: https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1

from collections import deque


class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


# Function to Build Tree
def buildTree(str):
    # Corner Case
    if len(str) == 0 or str[0] == "N":
        return None

    # Creating list of strings from input string after splitting by space
    ip = str.split()

    # Create the root of the tree
    root = Node(int(ip[0]))

    # Push the root to the queue
    queue = deque()
    queue.append(root)

    # Starting from the second element
    i = 1
    while queue and i < len(ip):
        # Get and remove the front of the queue
        currNode = queue.popleft()

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if currVal != "N":
            # Create the left child for the current node
            currNode.left = Node(int(currVal))

            # Push it to the queue
            queue.append(currNode.left)

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
            queue.append(currNode.right)

        i += 1

    return root


class Solution:
    def absolute_diff(self, root):
        ans = float("inf")
        stack = []
        curr = root
        prev = None
        while curr or stack:
            while curr: 
                stack.append(curr)
                curr = curr.left
            curr = stack.pop()
            if prev:
                ans = min(ans, abs(prev.data - curr.data))
            prev = curr
            curr = curr.right
        return ans


if __name__ == "__main__":
    obj = Solution()
    s = "50 30 70 20 N 60 80"
    root = buildTree(s)
    print(obj.absolute_diff(root))
    s = "60 30 90 10 N N N"
    root = buildTree(s)
    print(obj.absolute_diff(root))
