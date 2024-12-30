# Link: https://www.geeksforgeeks.org/problems/remove-k-digits/1


class Solution:
    def removeKdigits(self, S, K):
        n = len(S)
        v = [0] * 10
        st = []

        for i in range(n):
            while st and S[i] < st[-1] and K > 0:
                st.pop()
                K -= 1
            if not st and S[i] == "0":
                continue
            st.append(S[i])

        while st and K > 0:
            st.pop()
            K -= 1

        if not st:
            return "0"

        ans = ""
        while st:
            ans += st.pop()

        return ans[::-1]


if __name__ == "__main__":
    obj = Solution()
    S = "149811"
    K = 3
    print(obj.removeKdigits(S, K))
    S = "1002991"
    K = 3
    print(obj.removeKdigits(S, K))
