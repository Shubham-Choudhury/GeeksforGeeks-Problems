# Link: https://www.geeksforgeeks.org/problems/convert-to-strictly-increasing-array3351/1


class Solution:
    def min_operations(self, nums):
        n = len(nums)
        LIS = [1] * n
        for i in range(1, n):
            for j in range(i):
                if nums[i] > nums[j] and (i - j) <= (nums[i] - nums[j]):
                    LIS[i] = max(LIS[i], LIS[j] + 1)

        return n - max(LIS)


if __name__ == "__main__":
    obj = Solution()
    nums = [1, 2, 3, 6, 5, 4]
    print(obj.min_operations(nums))
    nums = [1, 1, 1, 1]
    print(obj.min_operations(nums))
