# Link: https://www.geeksforgeeks.org/problems/coverage-of-all-zeros-in-a-binary-matrix4024/1

class Solution:
    def FindCoverage(self, matrix):
        n = len(matrix)
        m = len(matrix[0])

        ans = 0

        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 1:
                    continue

                if i + 1 < n:
                    ans += matrix[i + 1][j]
                if j + 1 < m:
                    ans += matrix[i][j + 1]
                if i >= 1:
                    ans += matrix[i - 1][j]
                if j >= 1:
                    ans += matrix[i][j - 1]

        return ans


if __name__ == "__main__":
    obj = Solution()
    matrix = [[0, 1, 0], [0, 1, 1], [0, 0, 0]]
    print(obj.FindCoverage(matrix))

    matrix = [[0, 1]]
    print(obj.FindCoverage(matrix))
