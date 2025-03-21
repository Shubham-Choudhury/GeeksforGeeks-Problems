# Link: https://www.geeksforgeeks.org/problems/house-robber-ii/1


class Solution:
    def helper(self, nums):
        n = len(nums)
        dp = [0] * n
        dp[0] = nums[0]
        for i in range(1, n):
            pick = nums[i]
            if i > 1:
                pick += dp[i - 2]
            non = dp[i - 1]
            dp[i] = max(pick, non)
        return dp[-1]

    def maxValue(self, arr):
        n = len(arr)
        if n == 0:
            return 0
        if n == 1:
            return arr[0]
        arr1 = arr[:-1]
        arr2 = arr[1:]
        ans1 = self.helper(arr1)
        ans2 = self.helper(arr2)
        return max(ans1, ans2)


if __name__ == "__main__":
    obj = Solution()
    arr = [2, 3, 2]
    print(obj.maxValue(arr))

    arr = [1, 2, 3, 1]
    print(obj.maxValue(arr))

    arr = [2, 2, 3, 1, 2]
    print(obj.maxValue(arr))
