# Link: https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

from bisect import bisect_right


class Solution:
    def median(self, mat):
        n = len(mat)
        m = len(mat[0])

        minVal = float("inf")
        maxVal = float("-inf")

        for i in range(n):
            minVal = min(minVal, mat[i][0])
            maxVal = max(maxVal, mat[i][m - 1])

        desired = (n * m + 1) // 2
        lo = minVal
        hi = maxVal

        while lo < hi:
            mid = lo + (hi - lo) // 2
            place = 0

            for i in range(n):
                place += bisect_right(mat[i], mid)

            if place < desired:
                lo = mid + 1
            else:
                hi = mid

        return lo


if __name__ == "__main__":
    sol = Solution()
    mat = [[1, 3, 5], [2, 6, 9], [3, 6, 9]]
    result = sol.median(mat)
    print(f"The median is: {result}")

    mat = [[2, 4, 9], [3, 6, 7], [4, 7, 10]]
    result = sol.median(mat)
    print(f"The median is: {result}")

    mat = [[3], [4], [8]]
    result = sol.median(mat)
    print(f"The median is: {result}")
