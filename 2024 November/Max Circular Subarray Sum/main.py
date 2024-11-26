# Link: https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1


class Solution:
    def circularSubarraySum(self, arr):
        n = len(arr)
        maxsum = float("-inf")
        sum = 0
        totalsum = 0

        for i in range(n):
            sum += arr[i]
            totalsum += arr[i]
            maxsum = max(maxsum, sum)
            if sum < 0:
                sum = 0

        minsum = float("inf")
        sum1 = 0

        for i in range(n):
            sum1 += arr[i]
            minsum = min(minsum, sum1)
            if sum1 > 0:
                sum1 = 0

        if maxsum < 0:
            return maxsum
        return max(maxsum, totalsum - minsum)


if __name__ == "__main__":
    object = Solution()
    arr = [8, -8, 9, -9, 10, -11, 12]
    print(object.circularSubarraySum(arr))

    arr = [10, -3, -4, 7, 6, 5, -4, -1]
    print(object.circularSubarraySum(arr))

    arr = [-1, 40, -14, 7, 6, 5, -4, -1]
    print(object.circularSubarraySum(arr))
