# Link: https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1


class Solution:
    def maxGold(self, mat):
        n = len(mat)
        m = len(mat[0])

        for y in range(m - 2, -1, -1):
            for x in range(n):
                max_prev = 0

                if x - 1 >= 0:
                    max_prev = max(max_prev, mat[x - 1][y + 1])

                max_prev = max(max_prev, mat[x][y + 1])

                if x + 1 < n:
                    max_prev = max(max_prev, mat[x + 1][y + 1])

                mat[x][y] += max_prev

        return max(mat[i][0] for i in range(n))


if __name__ == "__main__":
    sol = Solution()
    mat = [[1, 3, 3], [2, 1, 4], [0, 6, 4]]
    result = sol.maxGold(mat)
    print(f"Maximum amount of gold {result}")

    mat = [[1, 3, 1, 5], [2, 2, 4, 1], [5, 0, 2, 3], [0, 6, 1, 2]]
    result = sol.maxGold(mat)
    print(f"Maximum amount of gold {result}")

    mat = [[1, 3, 3], [2, 1, 4], [0, 7, 5]]
    result = sol.maxGold(mat)
    print(f"Maximum amount of gold {result}")
