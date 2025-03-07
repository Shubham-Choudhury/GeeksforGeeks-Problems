# Link: https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1

class Solution:
    def longestPalindrome(self, s):
        n = len(s)
        ans = 1
        dp = [[False] * (n + 1) for _ in range(n + 1)]
        ansstring = s[0]

        for i in range(n):
            dp[i][i] = True

        for i in range(n - 1, 0, -1):
            if s[i] == s[i - 1]:
                dp[i - 1][i] = True
                ans = 2
                ansstring = s[i - 1 : i + 1]

        for length in range(3, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                if s[i] == s[j] and dp[i + 1][j - 1]:
                    dp[i][j] = True
                    if length > ans:
                        ans = length
                        ansstring = s[i : j + 1]

        return ansstring


if __name__ == "__main__":
    obj = Solution()
    s = "forgeeksskeegfor"
    print(obj.longestPalindrome(s))

    s = "Geeks"
    print(obj.longestPalindrome(s))

    s = "abc"
    print(obj.longestPalindrome(s))
