# Link: https://www.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1


class Solution:
    def caseSort(self, s):
        n = len(s)

        lower = [0] * 26
        upper = [0] * 26

        for ch in s:
            if ch.islower():
                lower[ord(ch) - ord("a")] += 1
            else:
                upper[ord(ch) - ord("A")] += 1

        result = list(s)
        l, u = 0, 0

        for i in range(n):
            if s[i].islower():
                while lower[l] == 0:
                    l += 1
                result[i] = chr(ord("a") + l)
                lower[l] -= 1
            else:
                while upper[u] == 0:
                    u += 1
                result[i] = chr(ord("A") + u)
                upper[u] -= 1

        return "".join(result)


if __name__ == "__main__":
    sol = Solution()
    s = "GEekS"
    print(sol.caseSort(s))

    s = "XWMSPQ"
    print(sol.caseSort(s))
