# Link: https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/1


class Solution:
    def maxSum(self, arr):
        n = len(arr)
        ans = float("-inf")

        for i in range(1, n):
            ans = max(arr[i] + arr[i - 1], ans)

        return ans


if __name__ == "__main__":
    sol = Solution()
    arr = [4, 3, 5, 1]
    result = sol.maxSum(arr)
    print(f"Maximum sum of adjacent elements: {result}")

    arr = [1, 2, 3]
    result = sol.maxSum(arr)
    print(f"Maximum sum of adjacent elements: {result}")
