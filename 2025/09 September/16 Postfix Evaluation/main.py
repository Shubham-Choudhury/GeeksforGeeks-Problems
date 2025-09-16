# Link: https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

import math


class Solution:
    def evaluatePostfix(self, arr):
        st = []

        for token in arr:
            if token[0].isdigit() or (len(token) > 1 and token[0] == "-"):
                st.append(int(token))
            else:
                val1 = st.pop()
                val2 = st.pop()

                if token == "+":
                    st.append(val2 + val1)
                elif token == "-":
                    st.append(val2 - val1)
                elif token == "*":
                    st.append(val2 * val1)
                elif token == "/":
                    st.append(val2 // val1)
                elif token == "^":
                    st.append(int(math.pow(val2, val1)))
        return st.pop()


if __name__ == "__main__":
    obj = Solution()
    arr = ["2", "3", "1", "*", "+", "9", "-"]
    result = obj.evaluatePostfix(arr)
    print(f"Result: {result}")

    arr = ["2", "3", "^", "1", "+"]
    result = obj.evaluatePostfix(arr)
    print(f"Result: {result}")
