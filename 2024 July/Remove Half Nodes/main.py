# Link: https://www.geeksforgeeks.org/problems/remove-half-nodes/1


class Node:

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def buildTree(s):
    if len(s) == 0 or s[0] == "N":
        return None

    ip = s.split()
    root = Node(int(ip[0]))

    queue = []
    queue.append(root)

    i = 1
    while len(queue) > 0 and i < len(ip):
        currNode = queue.pop(0)
        currVal = ip[i]

        if currVal != "N":
            currNode.left = Node(int(currVal))
            queue.append(currNode.left)

        i += 1
        if i >= len(ip):
            break

        currVal = ip[i]

        if currVal != "N":
            currNode.right = Node(int(currVal))
            queue.append(currNode.right)

        i += 1

    return root


def printInorder(root):
    if root is None:
        return

    printInorder(root.left)
    print(root.data, end=" ")
    printInorder(root.right)


class Solution:
    def RemoveHalfNodes(self, node):
        if node is None:
            return None
        node.left = self.RemoveHalfNodes(node.left)
        node.right = self.RemoveHalfNodes(node.right)
        if node.left is None and node.right is not None:
            return node.right
        if node.left is not None and node.right is None:
            return node.left
        return node


if __name__ == "__main__":
    obj = Solution()
    s = "5 7 8 2"
    root = buildTree(s)
    print("Inorder Traversal of the tree before removing half nodes: ", end="")
    printInorder(root)
    print()
    root = obj.RemoveHalfNodes(root)
    print("Inorder Traversal of the tree after removing half nodes: ", end="")
    printInorder(root)
    print()

    s = "2 7 5"
    root = buildTree(s)
    print("Inorder Traversal of the tree before removing half nodes: ", end="")
    printInorder(root)
    print()
    root = obj.RemoveHalfNodes(root)
    print("Inorder Traversal of the tree after removing half nodes: ", end="")
    printInorder(root)
    print()
