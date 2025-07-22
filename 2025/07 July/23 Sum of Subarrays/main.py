# Link: https://www.geeksforgeeks.org/problems/sum-of-subarrays2229/1


class Solution:
    def subarraySum(self, arr):
        n = len(arr)
        result = 0

        for i in range(n):
            result += arr[i] * (i + 1) * (n - i)

        return result


if __name__ == "__main__":
    sol = Solution()
    arr = [1, 2, 3]
    result = sol.subarraySum(arr)
    print(f"Sum of all subarrays: {result}")

    arr = [1, 3]
    result = sol.subarraySum(arr)
    print(f"Sum of all subarrays: {result}")
