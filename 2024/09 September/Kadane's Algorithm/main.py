# Link: https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1


class Solution:
    def maxSubarraySum(self, arr):
        sum = 0
        ans = arr[0]

        for i in arr:
            sum += i
            ans = max(ans, sum)
            if sum < 0:
                sum = 0

        return ans


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 3, -2, 5]
    print(obj.maxSubarraySum(arr))
    arr = [-1, -2, -3, -4]
    print(obj.maxSubarraySum(arr))
    arr = [5, 4, 7]
    print(obj.maxSubarraySum(arr))
