# Link: https://www.geeksforgeeks.org/problems/search-in-fully-rotated-sorted-2d-matrix/1


class Solution:
    def searchMatrix(self, mat, x):
        n = len(mat)
        m = len(mat[0])

        low, high = 0, n * m - 1

        while low <= high:
            mid = low + (high - low) // 2

            row = mid // m
            col = mid % m
            midVal = mat[row][col]

            if midVal == x:
                return True

            lowRow = low // m
            lowCol = low % m
            lowVal = mat[lowRow][lowCol]

            if lowVal <= midVal:
                if lowVal <= x < midVal:
                    high = mid - 1
                else:
                    low = mid + 1
            else:
                highRow = high // m
                highCol = high % m
                highVal = mat[highRow][highCol]

                if midVal < x <= highVal:
                    low = mid + 1
                else:
                    high = mid - 1

        return False


if __name__ == "__main__":
    sol = Solution()
    mat = [[7, 8, 9, 10], [11, 12, 13, 1], [2, 3, 4, 5]]
    x = 3
    result = sol.searchMatrix(mat, x)
    print(f"Element {x} found in matrix: {result}")

    mat = [[6, 7, 8], [9, 1, 2], [3, 4, 5]]
    x = 10
    result = sol.searchMatrix(mat, x)
    print(f"Element {x} found in matrix: {result}")
