# Link: https://www.geeksforgeeks.org/problems/edit-distance3702/1


class Solution:
    def editDistance(self, s1, s2):
        dp = [[0] * (len(s2) + 1) for _ in range(len(s1) + 1)]

        for i in range(len(s1)):
            dp[i + 1][0] = i + 1

        for i in range(len(s2)):
            dp[0][i + 1] = i + 1

        for i in range(len(s1)):
            for j in range(len(s2)):
                if s1[i] == s2[j]:
                    dp[i + 1][j + 1] = dp[i][j]
                else:
                    dp[i + 1][j + 1] = min(dp[i + 1][j], dp[i][j + 1], dp[i][j]) + 1

        return dp[-1][-1]


if __name__ == "__main__":
    obj = Solution()
    s1 = "geek"
    s2 = "gesek"
    print(obj.editDistance(s1, s2))

    s1 = "gfg"
    s2 = "gfg"
    print(obj.editDistance(s1, s2))

    s1 = "abcd"
    s2 = "bcfe"
    print(obj.editDistance(s1, s2))
