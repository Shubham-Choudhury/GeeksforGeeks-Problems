# Link: https://www.geeksforgeeks.org/problems/minimum-points-to-reach-destination0540/1


class Solution:
    def minPoints(self, m, n, points):
        dp = [[0] * n for _ in range(m)]
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if i == m - 1 and j == n - 1:
                    dp[i][j] = max(1, 1 - points[i][j])
                elif i == m - 1:
                    dp[i][j] = max(1, dp[i][j + 1] - points[i][j])
                elif j == n - 1:
                    dp[i][j] = max(1, dp[i + 1][j] - points[i][j])
                else:
                    dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - points[i][j])

        return dp[0][0]


if __name__ == "__main__":
    obj = Solution()
    points = [[-2, -3, 3], [-5, -10, 1], [10, 30, -5]]
    m = len(points)
    n = len(points[0])
    print(obj.minPoints(m, n, points))
    points = [[2, 3], [5, 10], [10, 30]]
    m = len(points)
    n = len(points[0])
    print(obj.minPoints(m, n, points))
