# Link: https://www.geeksforgeeks.org/problems/maximum-sum-of-hour-glass3842/1


class Solution:
    def findMaxSum(self, n, m, mat):
        if n < 3 or m < 3:
            return -1
        max_sum = float("-inf")
        for i in range(n - 2):
            for j in range(m - 2):
                curr_sum = (
                    mat[i][j]
                    + mat[i][j + 1]
                    + mat[i][j + 2]
                    + mat[i + 1][j + 1]
                    + mat[i + 2][j]
                    + mat[i + 2][j + 1]
                    + mat[i + 2][j + 2]
                )
                max_sum = max(max_sum, curr_sum)
        return max_sum if max_sum != float("-inf") else -1


if __name__ == "__main__":
    obj = Solution()
    mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    n = len(mat)
    m = len(mat[0])
    print(obj.findMaxSum(n, m, mat))

    mat = [[1, 2, 3], [4, 5, 6]]
    n = len(mat)
    m = len(mat[0])
    print(obj.findMaxSum(n, m, mat))
