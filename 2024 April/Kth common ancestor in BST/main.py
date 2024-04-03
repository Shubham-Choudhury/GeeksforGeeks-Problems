# Link: https://www.geeksforgeeks.org/problems/kth-common-ancestor-in-bst/1


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
    def kthCommonAncestor(self, root, k, x, y):
        if x > y:
            x, y = y, x
        ancs, node = [root.data], root
        while not (x <= node.data <= y):
            if x < node.data:
                node = node.left
            else:
                node = node.right
            ancs.append(node.data)
        if len(ancs) >= k:
            return ancs[-k]
        else:
            return -1


if __name__ == "__main__":
    obj = Solution()
    s = "10 50 40 N N 20 30 N N N N"
    root = buildTree(s)
    k = 2
    x = 20
    y = 30
    print(obj.kthCommonAncestor(root, k, x, y))
    s = "80 40 30 70 N 60 70"
    root = buildTree(s)
    k = 2
    x = 70
    y = 60
    print(obj.kthCommonAncestor(root, k, x, y))
