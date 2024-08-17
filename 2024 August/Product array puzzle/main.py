# Link: https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1


class Solution:
    def productExceptSelf(self, nums):
        n = len(nums)
        result = [1] * n
        left = 1
        right = 1
        for i in range(n):
            result[i] *= left
            result[n - i - 1] *= right
            left *= nums[i]
            right *= nums[n - i - 1]
        return result


if __name__ == "__main__":
    obj = Solution()
    nums = [10, 3, 5, 6, 2]
    ans = obj.productExceptSelf(nums)
    print(" ".join(map(str, ans)))

    nums = [12, 0]
    ans = obj.productExceptSelf(nums)
    print(" ".join(map(str, ans)))
