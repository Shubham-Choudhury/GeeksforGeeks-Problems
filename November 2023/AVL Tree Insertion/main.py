# Link: https://www.geeksforgeeks.org/problems/avl-tree-insertion/1


class Node:
    def _init_(self, x):
        self.data = x
        self.left = None
        self.right = None
        self.height = 1


class Solution:
    def getHeight(self, node):
        return 0 if not node else node.height

    def getBalance(self, root):
        return (
            0 if not root else (self.getHeight(root.left) - self.getHeight(root.right))
        )

    def leftRotate(self, root):
        y = root.right
        t2 = y.left
        root.right = t2
        y.left = root
        root.height = 1 + max(self.getHeight(root.left), self.getHeight(root.right))
        y.height = 1 + max(self.getHeight(y.left), self.getHeight(y.right))
        return y

    def rightRotate(self, root):
        y = root.left
        t2 = y.right
        root.left = t2
        y.right = root
        root.height = 1 + max(self.getHeight(root.left), self.getHeight(root.right))
        y.height = 1 + max(self.getHeight(y.left), self.getHeight(y.right))
        return y

    def insertToAVL(self, root, key):
        # add key to AVL (if it is not present already)
        # return root node
        if not root:
            root = Node(key)
            return root
        elif key == root.data:
            return root
        elif key < root.data:
            root.left = self.insertToAVL(root.left, key)
        else:
            root.right = self.insertToAVL(root.right, key)

        root.height = 1 + max(self.getHeight(root.left), self.getHeight(root.right))

        b = self.getBalance(root)
        if b > 1 and key < root.left.data:
            return self.rightRotate(root)

        if b < -1 and key > root.right.data:
            return self.leftRotate(root)

        if b > 1 and key > root.left.data:
            root.left = self.leftRotate(root.left)
            return self.rightRotate(root)

        if b < -1 and key < root.right.data:
            root.right = self.rightRotate(root.right)
            return self.leftRotate(root)
        return root


if __name__=="__main__":
    obj = Solution()
    root = None
    root = obj.insertToAVL(root, 10)
    root = obj.insertToAVL(root, 20)