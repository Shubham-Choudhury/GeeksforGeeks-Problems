# Link: https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1


class Solution:
    def getLPSLength(self, s):
        n = len(s)

        lps = [0] * n

        len_ = 0
        i = 1

        while i < n:
            if s[i] == s[len_]:
                len_ += 1
                lps[i] = len_
                i += 1
            else:
                if len_ != 0:
                    len_ = lps[len_ - 1]
                else:
                    lps[i] = 0
                    i += 1

        return lps[n - 1]


if __name__ == "__main__":
    sol = Solution()
    s = "abab"
    result = sol.getLPSLength(s)
    print(
        f"The length of the longest prefix which is also a suffix for '{s}' is: {result}"
    )

    s = "aabcdaabc"
    result = sol.getLPSLength(s)
    print(
        f"The length of the longest prefix which is also a suffix for '{s}' is: {result}"
    )

    s = "aaaa"
    result = sol.getLPSLength(s)
    print(
        f"The length of the longest prefix which is also a suffix for '{s}' is: {result}"
    )
