# Link: https://www.geeksforgeeks.org/problems/edit-distance3702/1


class Solution:
    def editDistance(self, str1, str3):
        dp = [[0] * (len(str3) + 1) for _ in range(len(str1) + 1)]

        for j in range(len(str3) + 1):
            dp[len(str1)][j] = len(str3) - j

        for i in range(len(str1) + 1):
            dp[i][len(str3)] = len(str1) - i

        for i in range(len(str1) - 1, -1, -1):
            for j in range(len(str3) - 1, -1, -1):
                if str1[i] == str3[j]:
                    dp[i][j] = dp[i + 1][j + 1]
                else:
                    insert = 1 + dp[i][j + 1]
                    delete = 1 + dp[i + 1][j]
                    replace = 1 + dp[i + 1][j + 1]
                    dp[i][j] = min(insert, delete, replace)

        return dp[0][0]


if __name__ == "__main__":
    obj = Solution()
    str1 = "geek"
    str2 = "gesek"
    print(obj.editDistance(str1, str2))

    str1 = "gfg"
    str2 = "gfg"
    print(obj.editDistance(str1, str2))
