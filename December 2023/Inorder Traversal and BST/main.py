# Link: https://www.geeksforgeeks.org/problems/inorder-traversal-and-bst5855/1


class Solution:
    def isRepresentingBST(self, arr, N):
        # code here
        stack = []
        prev_val = float("-inf")

        for val in arr:
            if val <= prev_val:
                return 0

            while stack and stack[-1] < val:
                prev_val = stack.pop()

            stack.append(val)

        return 1


if __name__ == "__main__":
    obj = Solution()
    arr = [2, 4, 3]
    n = len(arr)
    print(obj.isRepresentingBST(arr, n))
