# Link: https://www.geeksforgeeks.org/problems/wildcard-pattern-matching/1


class Solution:
    def wildCard(self, pattern, string):
        m = len(string)
        n = len(pattern)

        dp = [[False] * (n + 1) for _ in range(m + 1)]

        dp[0][0] = True

        for j in range(1, n + 1):
            if pattern[j - 1] == "*":
                dp[0][j] = dp[0][j - 1]
            else:
                break

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if pattern[j - 1] == string[i - 1] or pattern[j - 1] == "?":
                    dp[i][j] = dp[i - 1][j - 1]
                elif pattern[j - 1] == "*":
                    dp[i][j] = dp[i][j - 1] or dp[i - 1][j]

        return 1 if dp[m][n] else 0


if __name__ == "__main__":
    obj = Solution()
    pattern = "ba*a?"
    string = "baaabab"
    print(obj.wildCard(pattern, string))
    pattern = "a*ab"
    string = "baaabab"
    print(obj.wildCard(pattern, string))
