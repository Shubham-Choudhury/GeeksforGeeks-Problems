# Link: https://www.geeksforgeeks.org/problems/lexicographically-largest-string-after-deleting-k-characters/1


class Solution:
    def maxSubseq(self, s: str, k: int) -> str:
        n = len(s)
        res = ""
        rem = n - k

        for i in range(n):
            while res and k > 0 and res[-1] < s[i]:
                res = res[:-1]
                k -= 1

            res += s[i]

        while k > 0:
            res = res[:-1]
            k -= 1

        return res


if __name__ == "__main__":
    sol = Solution()
    s = "ritz"
    k = 2
    print(sol.maxSubseq(s, k))

    s = "zebra"
    k = 3
    print(sol.maxSubseq(s, k))
