# Link: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1


class Solution:
    def longest_subarray(self, arr, k):
        prefix_sum_map = {}
        prefix_sum_map[0] = -1
        total_sum = 0
        n = len(arr)
        ans = 0

        for i in range(n):
            total_sum += arr[i]
            if (total_sum - k) in prefix_sum_map:
                ans = max(ans, i - prefix_sum_map[total_sum - k])
            if total_sum not in prefix_sum_map:
                prefix_sum_map[total_sum] = i

        return ans


if __name__ == "__main__":
    object = Solution()
    arr = [10, 5, 2, 7, 1, -10]
    k = 15
    print(object.longest_subarray(arr, k))

    arr = [-5, 8, -14, 2, 4, 12]
    k = -5
    print(object.longest_subarray(arr, k))

    arr = [10, -10, 20, 30]
    k = 5
    print(object.longest_subarray(arr, k))
