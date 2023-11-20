# Link: https://www.geeksforgeeks.org/problems/k-sum-paths/1


class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


class Solution:
    def sumK(self, root, k):
        # code here
        from collections import defaultdict

        ans = 0

        def walk(n, cache, p=0):
            nonlocal ans, k
            if not n:
                return
            cur = p + n.data
            ans += cache[cur - k]
            cache[cur] += 1
            walk(n.left, cache, cur)
            walk(n.right, cache, cur)
            cache[cur] -= 1

        cache = defaultdict(int)
        cache[0] = 1
        walk(root, cache)
        return ans % (10**9 + 7)


if __name__ == "__main__":
    obj = Solution()
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
    print(obj.sumK(root, 5))
