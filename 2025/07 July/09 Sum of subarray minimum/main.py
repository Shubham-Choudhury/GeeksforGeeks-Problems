# Link: https://www.geeksforgeeks.org/problems/sum-of-subarray-minimum/1


class Solution:
    def sumSubMins(self, arr):
        n = len(arr)
        dp = [0] * n
        right = [i for i in range(n)]
        stack = []

        for i in range(n):
            while stack and arr[i] < arr[stack[-1]]:
                right[stack.pop()] = i
            stack.append(i)

        dp[n - 1] = arr[n - 1]
        for i in range(n - 2, -1, -1):
            r = right[i]
            if r == i:
                dp[i] = (n - i) * arr[i]
            else:
                dp[i] = (r - i) * arr[i] + dp[r]

        return sum(dp)


if __name__ == "__main__":
    sol = Solution()
    arr = [3, 1, 2, 4]
    result = sol.sumSubMins(arr)
    print(f"Total sum of the minimum elements of every possible subarrays is {result}")

    arr = [71, 55, 82, 55]
    result = sol.sumSubMins(arr)
    print(f"Total sum of the minimum elements of every possible subarrays is {result}")
