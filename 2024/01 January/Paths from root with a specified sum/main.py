# Link: https://www.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1


class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


class Solution:
    def printPaths(self, root, sum):
        if not root:
            return
        self.ans = []
        res = []
        self.pathsum(root, sum, res)
        return self.ans

    def pathsum(self, root, sm, res):
        if not root:
            return None
        sm -= root.data
        res.append(root.data)
        if sm == 0:
            self.ans.append(res.copy())

        self.pathsum(root.left, sm, res)
        self.pathsum(root.right, sm, res)
        res.pop()
        return None


if __name__ == "__main__":
    root = Node(1)
    root.left = Node(3)
    root.left.left = Node(2)
    root.left.right = Node(1)
    root.left.right.left = Node(1)
    root.right = Node(-1)
    root.right.left = Node(4)
    root.right.left.left = Node(1)
    root.right.left.right = Node(2)
    root.right.right = Node(5)
    root.right.right.right = Node(2)
    sum = 5
    ob = Solution()
    ans = ob.printPaths(root, sum)
    if len(ans) == 0:
        print(-1)
    else:
        for i in ans:
            for j in i:
                print(j, end=" ")
            print("$", end=" ")
        print()
