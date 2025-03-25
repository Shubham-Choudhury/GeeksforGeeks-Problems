# Link: https://www.geeksforgeeks.org/problems/word-break1352/1


class Solution:
    def __init__(self):
        self.dp = {}

    def solve(self, i, s, st):
        if i == len(s):
            return True
        if i in self.dp:
            return self.dp[i]

        temp = ""
        for j in range(i, len(s)):
            temp += s[j]
            if temp in st and self.solve(j + 1, s, st):
                self.dp[i] = True
                return True

        self.dp[i] = False
        return False

    def wordBreak(self, s, dictionary):
        st = set(dictionary)
        self.dp.clear()
        return self.solve(0, s, st)


if __name__ == "__main__":
    obj = Solution()
    s = "ilikegfg"
    dictionary = ["i", "like", "man", "india", "gfg"]
    print(obj.wordBreak(s, dictionary))

    s = "ilike"
    dictionary = ["i", "like", "gfg"]
    print(obj.wordBreak(s, dictionary))

    s = "ilikemangoes"
    dictionary = ["i", "like", "man", "india", "gfg"]
    print(obj.wordBreak(s, dictionary))
