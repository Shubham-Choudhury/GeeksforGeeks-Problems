# Link: https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1


class Solution:
    def missingNum(self, arr):
        n = len(arr) + 1
        total = (n * (n + 1)) // 2
        sum_arr = sum(arr)
        return total - sum_arr


if __name__ == "__main__":
    sol = Solution()
    arr = [1, 2, 3, 5]
    print("Missing number is:", sol.missingNum(arr))

    arr = [8, 2, 4, 5, 3, 7, 1]
    print("Missing number is:", sol.missingNum(arr))

    arr = [1]
    print("Missing number is:", sol.missingNum(arr))
