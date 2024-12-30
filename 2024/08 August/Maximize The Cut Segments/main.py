# Link: https://www.geeksforgeeks.org/problems/cutted-segments1642/1

import numpy as np


class Solution:
    def maximizeTheCuts(self, n, x, y, z):
        cut = [x, y, z]
        t = np.full((4, n + 1), -float("inf"))
        t[0][0] = 0

        for i in range(1, 4):
            for j in range(n + 1):
                if cut[i - 1] <= j:
                    t[i][j] = max(t[i - 1][j], t[i][j - cut[i - 1]] + 1)
                else:
                    t[i][j] = t[i - 1][j]

        return int(max(t[3][n], 0))


if __name__ == "__main__":
    obj = Solution()
    n = 5
    x = 5
    y = 3
    z = 2
    print(obj.maximizeTheCuts(n, x, y, z))

    n = 4
    x = 2
    y = 1
    z = 1
    print(obj.maximizeTheCuts(n, x, y, z))
