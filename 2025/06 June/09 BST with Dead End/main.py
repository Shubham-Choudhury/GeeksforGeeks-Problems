# Link: https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1


class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def insert(root, key):
    if root is None:
        return Node(key)
    if key < root.data:
        root.left = insert(root.left, key)
    else:
        root.right = insert(root.right, key)
    return root


def createBST(s):
    values = s.strip().split()
    root = None
    for val in values:
        if val == "N":
            continue
        num = int(val)
        root = insert(root, num)
    return root


class Solution:
    def dfs(self, root, mini, maxi):
        if root is None:
            return False
        if root.left is None and root.right is None and mini == maxi:
            return True
        return self.dfs(root.left, mini, root.data - 1) or self.dfs(
            root.right, root.data + 1, maxi
        )

    def isDeadEnd(self, root):
        return self.dfs(root, 1, float("inf"))


if __name__ == "__main__":
    sol = Solution()

    s1 = "8 5 9 2 7 N N 1"
    root1 = createBST(s1)
    print("Yes" if sol.isDeadEnd(root1) else "No")

    s2 = "8 7 10 2 N 9 13"
    root2 = createBST(s2)
    print("Yes" if sol.isDeadEnd(root2) else "No")
