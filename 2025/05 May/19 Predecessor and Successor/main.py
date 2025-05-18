# Link: https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

import queue


# BST Node
class Node:

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def buildTree(ip):
    # Corner Case
    if len(ip) == 0 or ip[0] == "N":
        return None

    # Create the root of the tree
    root = Node(int(ip[0]))

    # Push the root to the queue
    q = queue.Queue()
    q.put(root)

    # Starting from the second element
    i = 1
    while not q.empty() and i < len(ip):
        # Get and remove the front of the queue
        currNode = q.get()

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if currVal != "N":
            # Create the left child for the current node
            currNode.left = Node(int(currVal))

            # Push it to the queue
            q.put(currNode.left)

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
            q.put(currNode.right)

        i += 1

    return root


class Solution:
    def rightMost(self, node):
        while node.right is not None:
            node = node.right
        return node

    def leftMost(self, node):
        while node.left is not None:
            node = node.left
        return node

    def findPreSuc(self, root, key):
        pre = None
        suc = None
        curr = root

        while curr is not None:
            if curr.data < key:
                pre = curr
                curr = curr.right
            elif curr.data > key:
                suc = curr
                curr = curr.left
            else:
                if curr.left is not None:
                    pre = self.rightMost(curr.left)
                if curr.right is not None:
                    suc = self.leftMost(curr.right)
                break

        return [pre, suc]


if __name__ == "__main__":
    obj = Solution()
    s = "8 1 9 N 4 N 10 3 N N N"
    root = buildTree(s.split())
    key = 8
    pre, suc = obj.findPreSuc(root, key)
    if pre is not None:
        print(pre.data, end=" ")
    else:
        print(-1, end=" ")
    if suc is not None:
        print(suc.data)
    else:
        print(-1)

    s = "10 2 11 1 5 N N N N 3 6 N 4 N N"
    root = buildTree(s.split())
    key = 11
    pre, suc = obj.findPreSuc(root, key)
    if pre is not None:
        print(pre.data, end=" ")
    else:
        print(-1, end=" ")
    if suc is not None:
        print(suc.data)
    else:
        print(-1)
