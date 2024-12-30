# Link: https://www.geeksforgeeks.org/problems/maximum-sum-of-smallest-and-second-smallest-in-an-array/1


class Solution:
    def pairWithMaxSum(self, arr):
        if len(arr) < 2:
            return -1
        res = arr[0] + arr[1]
        for i in range(1, len(arr) - 1):
            res = max(res, arr[i] + arr[i + 1])
        return res


if __name__ == "__main__":
    obj = Solution()
    arr = [4, 3, 1, 5, 6]
    print(obj.pairWithMaxSum(arr))

    arr = [1]
    print(obj.pairWithMaxSum(arr))
