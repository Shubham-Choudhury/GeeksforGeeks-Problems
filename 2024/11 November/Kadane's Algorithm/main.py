# Link: https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1


class Solution:
    def maxSubarraySum(self, arr):
        max_sum = arr[0]
        current_sum = 0
        for i in range(len(arr)):
            current_sum += arr[i]
            max_sum = max(max_sum, current_sum)
            if current_sum < 0:
                current_sum = 0
        return max_sum


if __name__ == "__main__":
    object = Solution()
    arr = [2, 3, -8, 7, -1, 2, 3]
    print(object.maxSubarraySum(arr))

    arr = [-2, -4]
    print(object.maxSubarraySum(arr))

    arr = [5, 4, 1, 7, 8]
    print(object.maxSubarraySum(arr))
