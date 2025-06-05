# Link: https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1


class Solution:
    def search(self, pat, txt):
        d = 256
        q = 101
        m = len(pat)
        n = len(txt)
        ph = 0
        th = 0
        h = 1
        res = []

        for i in range(m - 1):
            h = (h * d) % q

        for i in range(m):
            ph = (d * ph + ord(pat[i])) % q
            th = (d * th + ord(txt[i])) % q

        for i in range(n - m + 1):
            if ph == th:
                ok = True
                for j in range(m):
                    if txt[i + j] != pat[j]:
                        ok = False
                        break

                if ok:
                    res.append(i + 1)

            if i < n - m:
                th = (d * (th - ord(txt[i]) * h) + ord(txt[i + m])) % q
                if th < 0:
                    th += q

        return res


if __name__ == "__main__":
    obj = Solution()
    text = "birthdayboy"
    pattern = "birth"
    result = obj.search(pattern, text)
    if result:
        print("Pattern found at indices:", result)
    else:
        print("Pattern not found")

    text = "geeksforgeeks"
    pattern = "geek"
    result = obj.search(pattern, text)
    if result:
        print("Pattern found at indices:", result)
    else:
        print("Pattern not found")
