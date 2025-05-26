# Link: https://www.geeksforgeeks.org/problems/print-leaf-nodes-from-preorder-traversal-of-bst2657/1


class Solution:
    def leafNodes(self, preorder):
        s = []
        leaves = []
        n = len(preorder)

        for i in range(n - 1):
            found = False
            if preorder[i] > preorder[i + 1]:
                s.append(preorder[i])
            else:
                while s and preorder[i + 1] > s[-1]:
                    s.pop()
                    found = True

            if found:
                leaves.append(preorder[i])

        leaves.append(preorder[-1])

        return leaves


if __name__ == "__main__":
    obj = Solution()
    arr = [5, 2, 10]
    print(obj.leafNodes(arr))

    arr = [4, 2, 1, 3, 6, 5]
    print(obj.leafNodes(arr))

    arr = [8, 2, 5, 10, 12]
    print(obj.leafNodes(arr))
