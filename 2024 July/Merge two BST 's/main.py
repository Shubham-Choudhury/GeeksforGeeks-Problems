# Link: https://www.geeksforgeeks.org/problems/merge-two-bst-s/1


class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def buildTree(s):
    # Corner Case
    if len(s) == 0 or s[0] == "N":
        return None

    # Creating list of strings from input string after splitting by space
    ip = s.split()

    # Create the root of the tree
    root = Node(int(ip[0]))

    # Push the root to the queue
    queue = [root]

    # Starting from the second element
    i = 1
    while queue and i < len(ip):
        # Get and remove the front of the queue
        currNode = queue.pop(0)

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
    def inorder(self, root, arr):
        if not root:
            return
        self.inorder(root.left, arr)
        arr.append(root.data)
        self.inorder(root.right, arr)

    def merge(self, root1, root2):
        arr = []
        self.inorder(root1, arr)
        self.inorder(root2, arr)
        arr.sort()
        return arr


if __name__ == "__main__":
    obj = Solution()
    s1 = "5 3 6 2 4"
    s2 = "2 1 3 N N N 7 6"
    root1 = buildTree(s1)
    root2 = buildTree(s2)
    res = obj.merge(root1, root2)
    print(" ".join(map(str, res)))

    s1 = "12 9 N 6 11"
    s2 = "8 5 10 2"
    root1 = buildTree(s1)
    root2 = buildTree(s2)
    res = obj.merge(root1, root2)
    print(" ".join(map(str, res)))
