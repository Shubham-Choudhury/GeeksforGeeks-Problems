# Link: https://www.geeksforgeeks.org/problems/children-sum-parent/1


class Node:
    def init(self, val):
        self.data = val
        self.left = None
        self.right = None


class Solution:
    def __init__(self):
        self.flag = True

    def is_sum(self, root):
        if root is None:
            return 0
        if root.left is None and root.right is None:
            return root.data
        sum_ = self.is_sum(root.left) + self.is_sum(root.right)
        if sum_ != root.data:
            self.flag = False
        return root.data

    def is_sum_property(self, root):
        self.is_sum(root)
        return int(self.flag)
