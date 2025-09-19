# Link: https://www.geeksforgeeks.org/problems/min-add-to-make-parentheses-valid/1


class Solution:
    def minParentheses(self, s):
        n = len(s)
        unmatchedClosing = 0
        balance = 0

        for c in s:
            if c == "(":
                balance += 1

            elif c == ")":
                balance -= 1

                if balance < 0:
                    unmatchedClosing += 1
                    balance = 0

        unmatchedOpening = 0
        balance = 0
        for c in reversed(s):
            if c == ")":
                balance += 1

            elif c == "(":
                balance -= 1

                if balance < 0:
                    unmatchedOpening += 1
                    balance = 0

        return unmatchedClosing + unmatchedOpening


if __name__ == "__main__":
    sol = Solution()
    s = "(()("
    result = sol.minParentheses(s)
    print(f"Minimum parentheses to be added to make {s} valid is: {result}")

    s = ")))"
    result = sol.minParentheses(s)
    print(f"Minimum parentheses to be added to make {s} valid is: {result}")
