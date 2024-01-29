# Link: https://www.geeksforgeeks.org/problems/count-digit-groupings-of-a-number1520/1


class Solution:
    def solve(self, str, i, j, needed, dp):
        if i > j:
            return 1
        if i == j:
            return 1 if (int(str[i]) >= needed) else 0
        if dp[i][needed] != -1:
            return dp[i][needed]
        s = ""
        sum = 0
        ans = 0
        for k in range(i, j + 1):
            s += str[k]
            sum += int(str[k])
            if sum >= needed:
                ans += self.solve(str, k + 1, j, sum, dp)
        dp[i][needed] = ans
        return ans

    def TotalCount(self, s):
        needed = 0
        sum = 0
        for i in range(len(s)):
            sum += int(s[i])
        dp = [[-1 for _ in range(sum + 1)] for _ in range(len(s))]
        return self.solve(s, 0, len(s) - 1, needed, dp)


if __name__ == "__main__":
    obj = Solution()
    string = "1119"
    print(obj.TotalCount(string))
    string = "12"
    print(obj.TotalCount(string))
