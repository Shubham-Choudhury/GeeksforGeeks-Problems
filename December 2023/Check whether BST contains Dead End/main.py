# Link: https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

# Your task is to complete this function
# function should return true/false or 1/0

import math

class Solution:
    def isdeadEnd(self, root):
        # Code here

        return self.util(root, 0, math.inf)

    def util(self, root, left_bound, right_bound):
        if left_bound + 1 == root.data == right_bound - 1:
            return True

        left, right = False, False
        if root.left:
            left = self.util(root.left, left_bound, root.data)
            if left:
                return True
        if root.right:
            right = self.util(root.right, root.data, right_bound)
            if right:
                return True

        return left or right

