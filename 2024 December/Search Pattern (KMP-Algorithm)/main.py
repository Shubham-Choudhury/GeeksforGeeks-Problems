# Link: https://www.geeksforgeeks.org/problems/search-pattern0205/1


class Solution:
    def search(self, pat, txt):
        m = len(pat)
        lps = [0] * m
        i = 1
        prevlps = 0

        while i <= m - 1:
            if pat[prevlps] == pat[i]:
                lps[i] = prevlps + 1
                i += 1
                prevlps += 1
            else:
                if prevlps == 0:
                    lps[i] = 0
                    i += 1
                else:
                    prevlps = lps[prevlps - 1]

        i = 0
        j = 0
        ans = []

        while i <= len(txt) - 1:
            if pat[j] == txt[i]:
                i += 1
                j += 1
            else:
                if j == 0:
                    i += 1
                else:
                    j = lps[j - 1]
            if j == m:
                ans.append(i - j)
                j = lps[j - 1]

        return ans


if __name__ == "__main__":
    obj = Solution()
    txt = "abcab"
    pat = "ab"
    ans = obj.search(pat, txt)
    print(" ".join(map(str, ans)))

    txt = "abesdu"
    pat = "edu"
    ans = obj.search(pat, txt)
    print(" ".join(map(str, ans)))

    txt = "aabaacaadaabaaba"
    pat = "aaba"
    ans = obj.search(pat, txt)
    print(" ".join(map(str, ans)))
