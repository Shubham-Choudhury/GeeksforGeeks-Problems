# Link: https://www.geeksforgeeks.org/problems/sum-of-leaf-nodes-in-bst/1


class Node:
    def __init__(self, data=0):
        self.data = 0
        self.left = None
        self.right = None


class Solution:
    def sumOfLeafNodes(self, root):
        def od(r):
            if r:
                if r.left == None and r.right == None:
                    summation[0] += r.data
                else:
                    od(r.left)
                    od(r.right)

        summation = [0]
        od(root)
        return summation[0]


if __name__ == "__main__":
    obj = Solution()
    arr = [67, 34, 82, 12, 45, 78]
    root = Node(arr[0])
    for i in range(1, len(arr)):
        temp = Node(arr[i])
        p = root
        while 1:
            if temp.data < p.data:
                if p.left == None:
                    p.left = temp
                    break
                else:
                    p = p.left
            else:
                if p.right == None:
                    p.right = temp
                    break
                else:
                    p = p.right

    print(obj.sumOfLeafNodes(root))
    arr = [45]
    root = Node(arr[0])
    print(obj.sumOfLeafNodes(root))
