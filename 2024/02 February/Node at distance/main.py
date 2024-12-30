# Link: https://www.geeksforgeeks.org/problems/node-at-distance/1


class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


class Solution:
    def printKDistantfromLeaf(self, root, k):
        leaves = set()
        parent = {root: None}

        def dfs(n):
            if not n:
                return
            if not n.left and not n.right:
                leaves.add(n)
                return
            if n.left:
                parent[n.left] = n
            if n.right:
                parent[n.right] = n
            dfs(n.left)
            dfs(n.right)

        dfs(root)
        visited = set()
        ans = 0
        for e in leaves:
            n = 0
            while n < k and e:
                n += 1
                e = parent[e]
            if e and e not in visited:
                visited.add(e)
                ans += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)
    root.right.left.right = Node(8)
    print(obj.printKDistantfromLeaf(root, 2))
