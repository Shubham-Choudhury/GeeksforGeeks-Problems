# Link: https://www.geeksforgeeks.org/problems/word-break1352/1


class Solution:
    def wordBreak(self, line, dictionary):
        n = len(line)
        dp = [False] * (n + 1)
        dp[0] = True

        for i in range(1, n + 1):
            for word in dictionary:
                if i >= len(word) and line[i - len(word) : i] == word:
                    dp[i] = dp[i] or dp[i - len(word)]

        return dp[n]


if __name__ == "__main__":
    obj = Solution()
    dictionary = ["i", "like", "sam", "sung", "samsung", "mobile"]
    line = "ilike"
    print(obj.wordBreak(line, dictionary))
    line = "ilikesamsung"
    print(obj.wordBreak(line, dictionary))
