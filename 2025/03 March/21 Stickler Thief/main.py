# Link: https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1


class Solution:
    def findMaxSum(self, arr):
        temp, p = arr[0], 0
        for i in range(1, len(arr)):
            curr = arr[i]
            curr = max(curr + p, temp)
            p, temp = temp, curr
        return temp


if __name__ == "__main__":
    obj = Solution()
    arr = [6, 5, 5, 7, 4]
    print(obj.findMaxSum(arr))
    arr = [1, 5, 3]
    print(obj.findMaxSum(arr))
    arr = [4, 4, 4, 4]
    print(obj.findMaxSum(arr))
