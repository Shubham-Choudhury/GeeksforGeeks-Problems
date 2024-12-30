# Link: https://www.geeksforgeeks.org/problems/leaf-at-same-level/1

from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def newNode(val):
    temp = Node(val)
    temp.left = None
    temp.right = None
    return temp


def buildTree(str):
    if len(str) == 0 or str[0] == "N":
        return None

    ip = str.split()

    root = newNode(int(ip[0]))

    queue = deque()
    queue.append(root)

    i = 1
    while queue and i < len(ip):
        currNode = queue.popleft()

        currVal = ip[i]
        if currVal != "N":
            currNode.left = newNode(int(currVal))
            queue.append(currNode.left)

        i += 1
        if i >= len(ip):
            break
        currVal = ip[i]
        if currVal != "N":
            currNode.right = newNode(int(currVal))
            queue.append(currNode.right)

        i += 1

    return root


class Solution:
    def check(self, root):
        if not root:
            return True

        s = set()

        def dfs_travers(node, level):
            if not node:
                return
            if not node.left and not node.right:
                s.add(level)
                return
            dfs_travers(node.left, level + 1)
            dfs_travers(node.right, level + 1)

        dfs_travers(root, 0)

        return len(s) == 1


if __name__ == "__main__":
    obj = Solution()
    root = buildTree("1 2 3")
    print(obj.check(root))
    root = buildTree("10 20 30 10 15")
    print(obj.check(root))
