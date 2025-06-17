# Link: https://www.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1


class Solution:
    def palindromes(self, s, dp):
        n = len(s)

        for i in range(n):
            dp[i][i] = True

        for i in range(n - 1):
            dp[i][i + 1] = s[i] == s[i + 1]

        for length in range(3, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                dp[i][j] = (s[i] == s[j]) and dp[i + 1][j - 1]

    def backtrack(self, idx, s, curr, res, dp):
        if idx == len(s):
            res.append(list(curr))
            return

        for i in range(idx, len(s)):
            if dp[idx][i]:
                curr.append(s[idx : i + 1])
                self.backtrack(i + 1, s, curr, res, dp)
                curr.pop()

    def palinParts(self, s):
        n = len(s)
        dp = [[False] * n for _ in range(n)]

        self.palindromes(s, dp)

        res = []
        curr = []
        self.backtrack(0, s, curr, res, dp)
        return res


if __name__ == "__main__":
    sol = Solution()
    s = "geeks"
    result = sol.palinParts(s)
    print(result)

    s = "abcba"
    result = sol.palinParts(s)
    print(result)
