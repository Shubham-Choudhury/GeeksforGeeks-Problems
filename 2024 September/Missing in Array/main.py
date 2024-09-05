# Link: https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1


class Solution:
    def missingNumber(self, n, arr):
        total_sum = n * (n + 1) // 2
        current_sum = sum(arr)
        return total_sum - current_sum


if __name__ == "__main__":
    obj = Solution()
    n = 5
    arr = [1, 2, 3, 5]
    print(obj.missingNumber(n, arr))
    n = 2
    arr = [1]
    print(obj.missingNumber(n, arr))
