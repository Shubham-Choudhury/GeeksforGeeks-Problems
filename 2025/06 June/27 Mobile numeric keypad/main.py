# Link: https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1


class Solution:
    def getCount(self, n):
        ans = 0

        prev = [[1 for _ in range(3)] for _ in range(4)]
        prev[3][0] = 0
        prev[3][2] = 0

        curr = [[0 for _ in range(3)] for _ in range(4)]
        dir = [[0, 0], [0, -1], [0, 1], [-1, 0], [1, 0]]

        for k in range(2, n + 1):
            for i in range(4):
                for j in range(3):
                    curr[i][j] = 0

                    if i == 3 and (j == 0 or j == 2):
                        continue

                    for d in dir:
                        x, y = i + d[0], j + d[1]
                        if 0 <= x < 4 and 0 <= y < 3:
                            curr[i][j] += prev[x][y]

            for i in range(4):
                for j in range(3):
                    prev[i][j] = curr[i][j]

        for i in range(4):
            for j in range(3):
                ans += prev[i][j]

        return ans


if __name__ == "__main__":
    sol = Solution()
    n = 1
    print(sol.getCount(n))

    n = 2
    print(sol.getCount(n))
