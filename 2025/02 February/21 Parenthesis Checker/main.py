# Link: https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1


class Solution:
    def isBalanced(self, s):
        stack = []
        for ch in s:
            if ch in ["(", "{", "["]:
                stack.append(ch)
            else:
                if not stack:
                    return False
                if ch == ")" and stack[-1] == "(":
                    stack.pop()
                elif ch == "}" and stack[-1] == "{":
                    stack.pop()
                elif ch == "]" and stack[-1] == "[":
                    stack.pop()
                else:
                    return False
        return not stack


if __name__ == "__main__":
    obj = Solution()
    s = "[{()}]"
    print(obj.isBalanced(s))

    s = "[()()]{}"
    print(obj.isBalanced(s))

    s = "([]"
    print(obj.isBalanced(s))

    s = "([{]})"
    print(obj.isBalanced(s))
