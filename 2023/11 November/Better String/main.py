# Link: https://www.geeksforgeeks.org/problems/better-string/1


class Solution:
    def betterString(self, str1, str2):
        # Code here
        str1_subString_count, str2_subString_count = self.countSubsequences(
            str1
        ), self.countSubsequences(str2)
        return str2 if str2_subString_count > str1_subString_count else str1

    def countSubsequences(self, string):
        count = {}
        n = len(string)
        dp = [0] * (n + 1)
        dp[0] = 1

        for c in string:
            count[c] = -1

        for i in range(1, n + 1):
            dp[i] = 2 * dp[i - 1]
            if count[string[i - 1]] != -1:
                dp[i] = dp[i] - dp[count[string[i - 1]]]

            count[string[i - 1]] = i - 1

        return dp[n]


if __name__ == "__main__":
    obj = Solution()
    str1 = "gfg"
    str2 = "ggg"
    print(obj.betterString(str1, str2))
    str1 = "a"
    str2 = "b"
    print(obj.betterString(str1, str2))
