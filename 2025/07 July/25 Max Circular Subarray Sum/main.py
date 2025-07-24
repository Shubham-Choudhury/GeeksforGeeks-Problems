# Link: https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1


class Solution:
    def maxCircularSum(self, arr):
        totalSum = 0
        currMaxSum = 0
        currMinSum = 0
        maxSum = arr[0]
        minSum = arr[0]

        for i in range(len(arr)):
            currMaxSum = max(currMaxSum + arr[i], arr[i])
            maxSum = max(maxSum, currMaxSum)

            currMinSum = min(currMinSum + arr[i], arr[i])
            minSum = min(minSum, currMinSum)

            totalSum += arr[i]

        normalSum = maxSum
        circularSum = totalSum - minSum

        if minSum == totalSum:
            return normalSum

        return max(normalSum, circularSum)


if __name__ == "__main__":
    sol = Solution()
    arr = [8, -8, 9, -9, 10, -11, 12]
    result = sol.maxCircularSum(arr)
    print(f"Max Circular Subarray Sum: {result}")

    arr = [10, -3, -4, 7, 6, 5, -4, -1]
    result = sol.maxCircularSum(arr)
    print(f"Max Circular Subarray Sum: {result}")

    arr = [5, -2, 3, 4]
    result = sol.maxCircularSum(arr)
    print(f"Max Circular Subarray Sum: {result}")
