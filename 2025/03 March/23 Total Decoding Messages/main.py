# Link: https://www.geeksforgeeks.org/problems/total-decoding-messages1235/1


class Solution:
    def countWays(self, digits):
        if not digits or digits[0] == "0":
            return 0

        n = len(digits)
        dp = [0] * (n + 1)
        dp[0], dp[1] = 1, 1

        for i in range(2, n + 1):
            one_digit = int(digits[i - 1])
            two_digits = int(digits[i - 2 : i])

            if one_digit != 0:
                dp[i] += dp[i - 1]
            if 10 <= two_digits <= 26:
                dp[i] += dp[i - 2]

        return dp[n]


if __name__ == "__main__":
    obj = Solution()
    digits = "123"
    print(obj.countWays(digits))

    digits = "90"
    print(obj.countWays(digits))

    digits = "05"
    print(obj.countWays(digits))
