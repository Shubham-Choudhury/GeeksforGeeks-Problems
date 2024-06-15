# Link: https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1


class Solution:
    def getCount(self, n):
        neighbors = {
            0: [0, 8],
            1: [1, 2, 4],
            2: [1, 2, 3, 5],
            3: [2, 3, 6],
            4: [1, 4, 5, 7],
            5: [2, 4, 5, 6, 8],
            6: [3, 5, 6, 9],
            7: [4, 7, 8],
            8: [0, 5, 7, 8, 9],
            9: [6, 8, 9],
        }

        dp = [[0] * 10 for _ in range(n)]
        for i in range(10):
            dp[0][i] = 1

        for i in range(1, n):
            for k in range(10):
                dp[i][k] = 0
                for pre in neighbors[k]:
                    dp[i][k] += dp[i - 1][pre]
        return sum(dp[-1])


if __name__ == "__main__":
    obj = Solution()
    n = 1
    print(obj.getCount(n))
    n = 2
    print(obj.getCount(n))
