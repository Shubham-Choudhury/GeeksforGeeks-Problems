# Link: https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1


class Solution:
    def countWays(self, s):
        dp = {}

        def solve(i, j, isTrue):
            if i > j:
                return 0
            if i == j:
                return 1 if (s[i] == "T") == isTrue else 0

            if (i, j, isTrue) in dp:
                return dp[(i, j, isTrue)]

            ways = 0

            for k in range(i + 1, j, 2):
                leftT = solve(i, k - 1, True)
                leftF = solve(i, k - 1, False)
                rightT = solve(k + 1, j, True)
                rightF = solve(k + 1, j, False)

                if s[k] == "&":
                    if isTrue:
                        ways += leftT * rightT
                    else:
                        ways += leftT * rightF + leftF * rightT + leftF * rightF
                elif s[k] == "|":
                    if isTrue:
                        ways += leftT * rightT + leftT * rightF + leftF * rightT
                    else:
                        ways += leftF * rightF
                elif s[k] == "^":
                    if isTrue:
                        ways += leftT * rightF + leftF * rightT
                    else:
                        ways += leftT * rightT + leftF * rightF

            dp[(i, j, isTrue)] = ways
            return ways

        return solve(0, len(s) - 1, True)


if __name__ == "__main__":
    obj = Solution()
    s = "T|T&F^T"
    print(obj.countWays(s))
    s = "T^F|F"
    print(obj.countWays(s))
