# Link: https://www.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1


class Solution:
    def minChar(self, s):
        rev = s[::-1]
        n = len(s)
        s = s + "#" + rev
        lps = [0] * len(s)
        l = 0
        for i in range(1, len(s)):
            while l > 0 and s[i] != s[l]:
                l = lps[l - 1]
            if s[i] == s[l]:
                l += 1
            lps[i] = l

        return n - lps[-1]


if __name__ == "__main__":
    object = Solution()
    s = "abc"
    print(object.minChar(s))
    s = "aacecaaaa"
    print(object.minChar(s))
