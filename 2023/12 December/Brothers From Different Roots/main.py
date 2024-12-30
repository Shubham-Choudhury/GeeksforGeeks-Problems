# Link: https://www.geeksforgeeks.org/problems/brothers-from-different-root/1

# User function Template for python3


class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


class Solution:
    def countPairs(self, root1, root2, x):
        # code here.
        l = []
        r = []

        def ino(root1):
            if root1:
                ino(root1.left)
                l.append(root1.data)
                ino(root1.right)

        def pos(root2):
            if root2:
                pos(root2.right)
                r.append(root2.data)
                pos(root2.left)

        ino(root1)
        pos(root2)
        i = 0
        j = 0
        c = 0

        while i < len(l) and j < len(r):
            if l[i] + r[j] == x:
                c += 1
                i += 1
                j += 1
            elif l[i] + r[j] > x:
                j += 1
            else:
                i += 1
        return c


if __name__ == "__main__":
    obj = Solution()
    root1 = Node(5)
    root1.left = Node(3)
    root1.right = Node(7)
    root1.left.left = Node(2)
    root1.left.right = Node(4)
    root1.right.left = Node(6)
    root1.right.right = Node(8)

    root2 = Node(10)
    root2.left = Node(6)
    root2.right = Node(15)
    root2.left.left = Node(3)
    root2.left.right = Node(8)
    root2.right.left = Node(11)
    root2.right.right = Node(18)

    x = 16
    print(obj.countPairs(root1, root2, x))
