# Link: https://www.geeksforgeeks.org/problems/subarray-range-with-given-sum0128/1

from collections import defaultdict


class Solution:
    def subArraySum(self, arr, tar):
        prefix_sum_count = defaultdict(int)
        prefix_sum = 0
        count = 0

        prefix_sum_count[0] = 1

        for num in arr:
            prefix_sum += num
            if (prefix_sum - tar) in prefix_sum_count:
                count += prefix_sum_count[prefix_sum - tar]
            prefix_sum_count[prefix_sum] += 1

        return count


if __name__ == "__main__":
    obj = Solution()
    arr = [10, 2, -2, -20, 10]
    tar = -10
    print(obj.subArraySum(arr, tar))

    arr = [1, 4, 20, 3, 10, 5]
    tar = 33
    print(obj.subArraySum(arr, tar))
