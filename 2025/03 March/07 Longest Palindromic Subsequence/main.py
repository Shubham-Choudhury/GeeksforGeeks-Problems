# Link: https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1


class Solution:

    def longestPalinSubseq(self, s):
        cache = {}

        def helper(l, r):
            if l > r:
                return 0
            if (l, r) in cache:
                return cache[(l, r)]
            if s[l] == s[r]:
                if l == r:
                    cache[(l, r)] = 1 + helper(l + 1, r - 1)
                    return cache[(l, r)]
                else:
                    cache[(l, r)] = 2 + helper(l + 1, r - 1)
                    return cache[(l, r)]
            else:
                cache[(l, r)] = max(helper(l + 1, r), helper(l, r - 1))
                return cache[(l, r)]

        return helper(0, len(s) - 1)


if __name__ == "__main__":
    obj = Solution()
    s = "bbabcbcab"
    print(obj.longestPalinSubseq(s))

    s = "abcd"
    print(obj.longestPalinSubseq(s))

    s = "agbdba"
    print(obj.longestPalinSubseq(s))
