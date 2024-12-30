# Link: https://www.geeksforgeeks.org/problems/search-pattern0205/1


class Solution:
    def search(self, pat, txt):
        indices = []
        n = len(txt)
        m = len(pat)

        for i in range(n - m + 1):
            j = 0
            while j < m:
                if txt[i + j] != pat[j]:
                    break
                j += 1

            if j == m:
                indices.append(i + 1)

        if len(indices) == 0:
            return [-1]
        else:
            return indices


if __name__ == "__main__":
    obj = Solution()
    txt = "geeksforgeeks"
    pat = "geek"
    ans = obj.search(pat, txt)
    for i in ans:
        print(i, end=" ")
    print()

    txt = "abesdu"
    pat = "edu"
    ans = obj.search(pat, txt)
    for i in ans:
        print(i, end=" ")
