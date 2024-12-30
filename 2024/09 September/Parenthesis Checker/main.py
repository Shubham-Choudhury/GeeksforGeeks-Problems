# Link: https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1


class Solution:
    def ispar(self, x):
        st = []
        for char in x:
            if char in "([{":
                st.append(char)
            else:
                if not st:
                    return False
                if char == ")" and st[-1] == "(":
                    st.pop()
                elif char == "]" and st[-1] == "[":
                    st.pop()
                elif char == "}" and st[-1] == "{":
                    st.pop()
                else:
                    return False
        return len(st) == 0


if __name__ == "__main__":
    obj = Solution()
    s = "{([])}"
    print(obj.ispar(s))

    s = "()"
    print(obj.ispar(s))

    s = "([]"
    print(obj.ispar(s))
