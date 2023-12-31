# Link: https://www.geeksforgeeks.org/problems/binary-tree-to-cdll/1


class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


class Solution:
    # Function to convert binary tree into circular doubly linked list.
    def bTreeToClist(self, root):
        # Your code here
        lis = []

        def fun(root):
            if root == None:
                return
            fun(root.left)
            lis.append(root.data)
            fun(root.right)

        fun(root)
        temp = None
        head = None
        for i in lis:
            new = Node(i)
            if temp == None:
                temp = new
                head = temp
            else:
                temp.right = new
                new.left = temp
                temp = temp.right
        temp.right = head
        head.left = temp
        return head


if __name__ == "__main__":
    root = Node(10)
    root.left = Node(20)
    root.right = Node(30)
    root.left.left = Node(40)

    ob = Solution()
    head = ob.bTreeToClist(root)
    print(head.data)
    print(head.right.data)
    print(head.right.right.data)
    print(head.right.right.right.data)
    print(head.right.right.right.right.data)
