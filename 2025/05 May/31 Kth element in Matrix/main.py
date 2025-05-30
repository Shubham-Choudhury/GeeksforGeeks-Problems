# Link: https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1


class Solution:
    def count_smaller_equal(self, matrix, x):
        n = len(matrix)
        count = 0
        row, col = 0, n - 1

        while row < n and col >= 0:
            if matrix[row][col] <= x:
                count += col + 1
                row += 1
            else:
                col -= 1

        return count

    def kthSmallest(self, matrix, k):
        n = len(matrix)
        low, high = matrix[0][0], matrix[n - 1][n - 1]
        ans = 0

        while low <= high:
            mid = low + (high - low) // 2

            count = self.count_smaller_equal(matrix, mid)

            if count < k:
                low = mid + 1
            else:
                ans = mid
                high = mid - 1

        return ans


if __name__ == "__main__":
    obj = Solution()
    matrix = [[16, 28, 60, 64], [22, 41, 63, 91], [27, 50, 87, 93], [36, 78, 87, 94]]
    k = 3
    result = obj.kthSmallest(matrix, k)
    print(result)

    matrix = [[10, 20, 30, 40], [15, 25, 35, 45], [24, 29, 37, 48], [32, 33, 39, 50]]
    k = 7
    result = obj.kthSmallest(matrix, k)
    print(result)
