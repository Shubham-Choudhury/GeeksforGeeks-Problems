# Link: https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1


class Solution:
    def searchMatrix(self, mat, x):
        row = len(mat)
        col = len(mat[0])
        low, high = 0, row * col - 1
        while low <= high:
            mid = (low + high) // 2
            midVal = mat[mid // col][mid % col]
            if midVal == x:
                return True
            elif midVal < x:
                low = mid + 1
            else:
                high = mid - 1
        return False


if __name__ == "__main__":
    object = Solution()
    mat = [[1, 5, 9], [14, 20, 21], [30, 34, 43]]
    x = 14
    print(object.searchMatrix(mat, x))
    mat = [[1, 5, 9, 11], [14, 20, 21, 26], [30, 34, 43, 50]]
    x = 42
    print(object.searchMatrix(mat, x))
    mat = [[87, 96, 99], [101, 103, 111]]
    x = 101
    print(object.searchMatrix(mat, x))
