# Link: https://www.geeksforgeeks.org/problems/symmetric-tree/1


class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


class Solution:
    def isSymmetric(self, root):
        queue_left = [root]
        queue_right = [root]
        while queue_left and queue_right:
            cur_left, cur_right = queue_left.pop(0), queue_right.pop(0)
            if cur_left == None and cur_right == None:
                continue
            elif cur_left == None or cur_right == None:
                return False
            else:
                if cur_left.data != cur_right.data:
                    return False
                else:
                    for child in (cur_left.left, cur_left.right):
                        queue_left.append(child)
                    for child in (cur_right.right, cur_right.left):
                        queue_right.append(child)
        return True


if __name__ == "__main__":
    obj = Solution()
    root = Node(1)
    root.left = Node(2)
    root.right = Node(2)
    root.left.left = Node(3)
    root.left.right = Node(4)
    root.right.left = Node(4)
    root.right.right = Node(3)
    print(obj.isSymmetric(root))
