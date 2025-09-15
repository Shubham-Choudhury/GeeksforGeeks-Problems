# Link: https://www.geeksforgeeks.org/problems/string-stack--165812/1


class Solution:
    def stringStack(self, pat, tar):
        i = len(pat) - 1
        j = len(tar) - 1

        while i >= 0 and j >= 0:
            if pat[i] != tar[j]:
                i -= 2

            else:
                i -= 1
                j -= 1
        return j < 0


if __name__ == "__main__":
    sol = Solution()
    pat = "geuaek"
    tar = "geek"
    result = sol.stringStack(pat, tar)
    print(
        f"Can the target string '{tar}' be formed from the pattern string '{pat}'? {result}"
    )

    pat = "agiffghd"
    tar = "gfg"
    result = sol.stringStack(pat, tar)
    print(
        f"Can the target string '{tar}' be formed from the pattern string '{pat}'? {result}"
    )

    pat = "ufahs"
    tar = "aus"
    result = sol.stringStack(pat, tar)
    print(
        f"Can the target string '{tar}' be formed from the pattern string '{pat}'? {result}"
    )
