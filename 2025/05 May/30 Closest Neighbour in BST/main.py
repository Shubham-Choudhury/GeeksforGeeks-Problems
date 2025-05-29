# Link: https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1


class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


def createBinarySearchTree(s: str):
    if not s or s == "N":
        return None
    values = s.split()
    root = Node(int(values[0]))
    queue = [root]
    i = 1
    while i < len(values):
        current = queue.pop(0)
        if values[i] != "N":
            current.left = Node(int(values[i]))
            queue.append(current.left)
        i += 1
        if i < len(values) and values[i] != "N":
            current.right = Node(int(values[i]))
            queue.append(current.right)
        i += 1
    return root


class Solution:
    def findMaxFork(self, root, k):
        if root == None:
            return -1
        if root.data == k:
            return k
        elif root.data < k:
            ans = self.findMaxFork(root.right, k)
            if ans == -1:
                return root.data
            else:
                return ans
        elif root.data > k:
            return self.findMaxFork(root.left, k)


if __name__ == "__main__":
    obj = Solution()
    s = "10 7 15 2 8 11 16"
    k = 14
    root = createBinarySearchTree(s)
    ans = obj.findMaxFork(root, k)
    print(ans)
    s = "5 2 12 1 3 9 21 N N N N N N 19 25"
    k = 24
    root = createBinarySearchTree(s)
    ans = obj.findMaxFork(root, k)
    print(ans)
    s = "5 2 12 1 3 9 21 N N N N N N 19 25"
    k = 4
    root = createBinarySearchTree(s)
    ans = obj.findMaxFork(root, k)
    print(ans)
