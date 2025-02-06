# Link: https://www.geeksforgeeks.org/problems/construct-tree-1/1


class Node:

    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None


def printPostorder(n):
    if n is None:
        return
    printPostorder(n.left)
    printPostorder(n.right)
    print(n.data, end=" ")


class Solution:
    def buildTree(self, inorder, preorder):
        m = {v: i for i, v in enumerate(inorder)}
        self.i = 0

        def f(l, r):
            if l > r:
                return None
            root = Node(preorder[self.i])
            self.i += 1
            pos = m[root.data]
            root.left = f(l, pos - 1)
            root.right = f(pos + 1, r)
            return root

        return f(0, len(inorder) - 1)


if __name__ == "__main__":
    s = Solution()
    inorder = [1, 6, 8, 7]
    preorder = [1, 6, 7, 8]
    root = s.buildTree(inorder, preorder)
    printPostorder(root)
    print()

    inorder = [3, 1, 4, 0, 2, 5]
    preorder = [0, 1, 3, 4, 2, 5]
    root = s.buildTree(inorder, preorder)
    printPostorder(root)
    print()

    inorder = [2, 5, 4, 1, 3]
    preorder = [1, 2, 4, 5, 3]
    root = s.buildTree(inorder, preorder)
    printPostorder(root)
    print()
