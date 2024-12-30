# Link: https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

from typing import List


class Solution:
    def maxSquare(self, n: int, m: int, mat: List[List[int]]) -> int:
        dp = [[0] * m for _ in range(n)]
        max_side = 0

        for i in range(n):
            for j in range(m):
                if mat[i][j] == 1:
                    if i == 0 or j == 0:
                        dp[i][j] = 1
                    else:
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
                    max_side = max(max_side, dp[i][j])

        return max_side


if __name__ == "__main__":
    obj = Solution()
    mat = [
        [0, 1, 1, 0, 1],
        [1, 1, 0, 1, 0],
        [0, 1, 1, 1, 0],
        [1, 1, 1, 1, 0],
        [1, 1, 1, 1, 1],
        [0, 0, 0, 0, 0],
    ]
    n = len(mat)
    m = len(mat[0])
    print(obj.maxSquare(n, m, mat))

    mat = [[1, 1], [1, 1]]
    n = len(mat)
    m = len(mat[0])
    print(obj.maxSquare(n, m, mat))

    mat = [[0, 0], [0, 0]]
    n = len(mat)
    m = len(mat[0])
    print(obj.maxSquare(n, m, mat))
