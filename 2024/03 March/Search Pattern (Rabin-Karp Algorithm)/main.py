# Link: https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1


class Solution:
    def search(self, pattern, text):
        res = []
        p = len(pattern)
        t = len(text)
        for i in range(t - p + 1):
            if text[i : p + i] == pattern:
                res.append(i + 1)
        return res


if __name__ == "__main__":
    obj = Solution()
    text = "birthdayboy"
    pattern = "birth"
    print(obj.search(pattern, text))
    text = "geeksforgeeks"
    pattern = "geek"
    print(obj.search(pattern, text))
