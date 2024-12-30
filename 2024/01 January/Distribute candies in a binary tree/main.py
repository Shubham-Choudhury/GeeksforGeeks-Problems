# Link: https://www.geeksforgeeks.org/problems/distribute-candies-in-a-binary-tree/1


class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


class Solution:
    def distributeCandy(self, root):
        self.moves = 0

        def dfs(root):
            if not root:
                return 0

            left_requires = dfs(root.left)
            right_requires = dfs(root.right)

            self.moves += abs(left_requires) + abs(right_requires)
            remaining_coins = left_requires + right_requires + root.data - 1

            return remaining_coins

        dfs(root)
        return self.moves


if __name__ == "__main__":
    obj = Solution()
    root = Node(3)
    root.left = Node(0)
    root.right = Node(0)
    print(obj.distributeCandy(root))
    root1 = Node(0)
    root1.left = Node(3)
    root1.right = Node(0)
    print(obj.distributeCandy(root1))
