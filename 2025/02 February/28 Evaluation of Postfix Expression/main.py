# Link: https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1


class Solution:
    def evaluate(self, arr):
        stack = []
        operator = ["+", "-", "*", "/", "%"]
        for item in arr:
            if item not in operator:
                stack.append((item))
            else:
                first = int(stack.pop())
                second = int(stack.pop())
                if item == "+":
                    stack.append(second + first)
                if item == "-":
                    stack.append(second - first)
                if item == "*":
                    stack.append(second * first)
                if item == "/":
                    stack.append(second / first)
                if item == "%":
                    stack.append(second % first)
        return int(stack[-1])


if __name__ == "__main__":
    obj = Solution()
    arr = ["2", "3", "1", "*", "+", "9", "-"]
    print(obj.evaluate(arr))

    arr = ["100", "200", "+", "2", "/", "5", "*", "7", "+"]
    print(obj.evaluate(arr))
