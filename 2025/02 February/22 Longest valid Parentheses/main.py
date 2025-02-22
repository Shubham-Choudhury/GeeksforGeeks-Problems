# Link: https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1


class Solution:
    def maxLength(self, s):
        stack = [-1]
        max_length = 0
        for i in range(len(s)):
            if s[i] == "(":
                stack.append(i)
            else:
                stack.pop()
                if len(stack) == 0:
                    stack.append(i)
                else:
                    max_length = max(max_length, i - stack[-1])
        return max_length


if __name__ == "__main__":
    obj = Solution()
    s = "((()"
    print(obj.maxLength(s))

    s = ")()())"
    print(obj.maxLength(s))

    s = "())()"
    print(obj.maxLength(s))
