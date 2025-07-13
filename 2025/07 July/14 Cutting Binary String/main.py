# Link: https://www.geeksforgeeks.org/problems/cutting-binary-string1342/1


class Solution:
    def cuts(self, s):
        if s[0] == "0":
            return -1

        n = len(s)
        maxi = n + 1
        powersOf5 = set()

        val = 1
        while val <= 1e9:
            powersOf5.add(val)
            val *= 5

        dp = [maxi] * (n + 1)

        dp[n] = 0

        for i in range(n - 1, -1, -1):
            if s[i] == "0":
                continue

            num = 0
            for j in range(i, n):
                num = num * 2 + (1 if s[j] == "1" else 0)

                if num in powersOf5:
                    if dp[j + 1] != maxi:
                        dp[i] = min(dp[i], 1 + dp[j + 1])

        return -1 if dp[0] >= maxi else dp[0]


if __name__ == "__main__":
    sol = Solution()
    s = "101101101"
    result = sol.cuts(s)
    print(f"Minimum cuts needed: {result}")

    s = "1111101"
    result = sol.cuts(s)
    print(f"Minimum cuts needed: {result}")

    s = "00000"
    result = sol.cuts(s)
    print(f"Minimum cuts needed: {result}")
