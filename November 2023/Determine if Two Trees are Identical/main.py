# Link: https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1


class Node:
    def init(self, val):
        self.right = None
        self.data = val
        self.left = None


class Solution:
    # Function to check if two trees are identical.
    def isIdentical(self, root1, root2):
        # Code here
        if root1 and root2:
            if root1.data != root2.data:
                return False
            if not self.isIdentical(root1.left, root2.left):
                return False
            if not self.isIdentical(root1.right, root2.right):
                return False
            return True
        if root1 or root2:
            return False
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.isIdentical(Node(1), Node(1)))
    print(obj.isIdentical(Node(1), Node(2)))
    print(obj.isIdentical(Node(1), Node(1, Node(2), None)))
    print(obj.isIdentical(Node(1, Node(2), None), Node(1)))
