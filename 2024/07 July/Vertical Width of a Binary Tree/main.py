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


def solve(root, x, width):
    if not root:
        return
    width[0] = min(width[0], x)
    width[1] = max(width[1], x)
    solve(root.left, x - 1, width)
    solve(root.right, x + 1, width)


def verticalWidth(root):
    if not root:
        return 0
    width = [0, 0]  # [mini, maxi]
    solve(root, 0, width)
    return width[1] - width[0] + 1


if __name__ == "__main__":
    s = "1 2 3 4 5 6 7 N N N N N 8 9"
    root = buildTree(s)
    print(verticalWidth(root))

    s = "1 2 3"
    root = buildTree(s)
    print(verticalWidth(root))
