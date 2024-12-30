# Link: https://www.geeksforgeeks.org/problems/print-bracket-number4058/1


class Solution:
    def bracketNumbers(self, str):
        vec = []
        st = []
        o = 0
        c = 0
        for i in range(len(str)):
            if str[i] == "(":
                o += 1
                vec.append(o)
                st.append(o)
            elif str[i] == ")":
                a = st.pop()
                vec.append(a)
        return vec


if __name__ == "__main__":
    obj = Solution()
    str = "(aa(bdc))p(dee)"
    print(obj.bracketNumbers(str))

    str = "(((()("
    print(obj.bracketNumbers(str))
