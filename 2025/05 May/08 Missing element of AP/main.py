# Link: https://www.geeksforgeeks.org/problems/missing-element-of-ap2228/1


class Solution:
    def findMissing(self, arr):
        n = len(arr)

        if arr[1] - arr[0] == arr[n - 1] - arr[n - 2]:
            diff = arr[1] - arr[0]
        elif arr[1] - arr[0] == (arr[n - 1] - arr[0]) // n:
            diff = arr[1] - arr[0]
        else:
            diff = arr[n - 1] - arr[n - 2]

        if diff == 0:
            return arr[0]

        expected_sum = (2 * arr[0] + n * diff) * (n + 1) // 2
        actual_sum = sum(arr)

        return expected_sum - actual_sum


if __name__ == "__main__":
    sol = Solution()

    arr = [2, 4, 8, 10, 12, 14]
    print("The missing element is:", sol.findMissing(arr))

    arr = [1, 6, 11, 16, 21, 31]
    print("The missing element is:", sol.findMissing(arr))

    arr = [4, 7, 10, 13, 16]
    print("The missing element is:", sol.findMissing(arr))
