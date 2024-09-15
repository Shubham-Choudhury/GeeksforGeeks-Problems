# Link: https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1


class Solution:
    def maxLength(self, str):
        op = 0
        n = len(str)
        cl = 0
        ans = 0
        for i in range(n):
            if str[i] == "(":
                op += 1
            else:
                cl += 1
            if op == cl:
                ans = max(ans, op + cl)
            elif cl > op:
                op = 0
                cl = 0
        op = 0
        cl = 0
        for i in range(n - 1, -1, -1):
            if str[i] == "(":
                op += 1
            else:
                cl += 1
            if op == cl:
                ans = max(ans, op + cl)
            elif cl < op:
                op = 0
                cl = 0
        return ans


if __name__ == "__main__":
    obj = Solution()
    str = "((()"
    print(obj.maxLength(str))
    str = ")()())"
    print(obj.maxLength(str))
