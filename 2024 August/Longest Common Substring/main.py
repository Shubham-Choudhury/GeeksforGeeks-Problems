# Link: https://www.geeksforgeeks.org/problems/longest-common-substring1452/1


class Solution:
    def longestCommonSubstr(self, str1: str, str2: str) -> int:
        n = len(str1)
        m = len(str2)

        dp = [[0] * (m + 1) for _ in range(n + 1)]
        result = 0

        for i in range(n + 1):
            for j in range(m + 1):
                if i == 0 or j == 0:
                    dp[i][j] = 0
                elif str1[i - 1] == str2[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                    result = max(result, dp[i][j])
                else:
                    dp[i][j] = 0

        return result


if __name__ == "__main__":
    obj = Solution()

    str1 = "ABCDGH"
    str2 = "ACDGHR"
    print(obj.longestCommonSubstr(str1, str2))

    str1 = "ABC"
    str2 = "ACB"
    print(obj.longestCommonSubstr(str1, str2))
