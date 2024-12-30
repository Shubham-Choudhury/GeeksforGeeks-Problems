# Link: Link: https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1


# a new node
class Node:
    def __init__(self, data):
        self.data = data
        self.left = self.right = None


# This funtcion is here just to test
def preOrder(node):
    if node == None:
        return
    print(node.data, end=" ")
    preOrder(node.left)
    preOrder(node.right)


class Solution:
    @staticmethod
    def buildTree(In, post, n):
        def dfs(arr):
            if len(arr) == 0:
                return None
            while len(post):
                val = post.pop()
                root = Node(val)
                index = arr.index(val)
                leftnodes = arr[0:index]
                rightnodes = arr[index + 1 :]

                root.right = dfs(rightnodes)
                root.left = dfs(leftnodes)

                return root

        return dfs(In)


if __name__ == "__main__":
    obj = Solution()
    In = [4, 8, 2, 5, 1, 6, 3, 7]
    post = [8, 4, 5, 2, 6, 7, 3, 1]
    n = len(In)
    root = obj.buildTree(In, post, n)
    preOrder(root)
    print()

    In = [9, 5, 2, 3, 4]
    post = [5, 9, 3, 4, 2]
    n = len(In)
    root = obj.buildTree(In, post, n)
    preOrder(root)
    print()
