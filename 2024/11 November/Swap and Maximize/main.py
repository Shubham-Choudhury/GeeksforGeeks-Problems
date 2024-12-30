# Link: from typing import List


class Solution:
    def maxSum(self, arr):
        arr.sort()
        ans = []
        n = len(arr)
        i, j = 0, n - 1
        while i <= j:
            if i == j:
                ans.append(arr[i])
            else:
                ans.append(arr[i])
                ans.append(arr[j])
            i += 1
            j -= 1
        total_sum = 0
        for i in range(1, n):
            total_sum += abs(ans[i] - ans[i - 1])
        total_sum += abs(ans[n - 1] - ans[0])
        return total_sum


if __name__ == "__main__":
    object = Solution()
    arr = [4, 2, 1, 8]
    print(object.maxSum(arr))

    arr = [10, 12]
    print(object.maxSum(arr))
