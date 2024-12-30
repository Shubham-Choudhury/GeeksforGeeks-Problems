# Link: https://www.geeksforgeeks.org/problems/distinct-occurrences/1


class Solution:
    def sequenceCount(self, s, t):
        mod = 10**9 + 7
        n, m = len(s), len(t)
        dp = [0] * (m + 1)
        dp[0] = 1
        for i in range(1, n + 1):
            for j in range(min(i, m), 0, -1):
                if s[i - 1] == t[j - 1]:
                    dp[j] = (dp[j] + dp[j - 1]) % mod
        return dp[m]


if __name__ == "__main__":
    obj = Solution()
    s = "banana"
    t = "ban"
    print(obj.sequenceCount(s, t))
    s = "geeksforgeeks"
    t = "ge"
    print(obj.sequenceCount(s, t))
