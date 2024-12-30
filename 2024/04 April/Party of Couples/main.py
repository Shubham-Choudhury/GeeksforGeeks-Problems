# Link: https://www.geeksforgeeks.org/problems/alone-in-couple5507/1


class Solution:
    def findSingle(self, n, arr):
        ans = 0
        for i in arr:
            ans ^= i
        return ans


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 3, 2, 1]
    n = len(arr)
    print(obj.findSingle(n, arr))
    arr = [1, 2, 3, 5, 3, 2, 1, 4, 5, 6, 6]
    n = len(arr)
    print(obj.findSingle(n, arr))
