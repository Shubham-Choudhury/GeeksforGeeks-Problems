# Link: https://www.geeksforgeeks.org/problems/duplicate-subtrees/1


from collections import deque
from collections import defaultdict


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


def preord(root):
    if not root:
        return
    print(root.data, end=" ")
    preord(root.left)
    preord(root.right)


class Solution:
    def printAllDups(self, root):
        from collections import Counter

        counter = Counter()
        ans = []

        def walk(n):
            if not n:
                return None
            l = walk(n.left)
            r = walk(n.right)
            tree = (n.data, l, r)
            counter[tree] += 1
            if counter[tree] == 2:
                ans.append(n)
            return tree

        walk(root)
        return sorted(ans, key=lambda x: x.data)


if __name__ == "__main__":
    obj = Solution()
    s = "1 2 3 4 N 2 4 N N 4 N"
    root = buildTree(s)
    preord(root)
    print()
    duplicates = obj.printAllDups(root)
    for node in duplicates:
        print(node.data, end=" ")
    print()

    s = "5 4 6 3 4 N N N N 3 6 N N N N"
    root = buildTree(s)
    preord(root)
    print()
    duplicates = obj.printAllDups(root)
    for node in duplicates:
        print(node.data, end=" ")
    print()
