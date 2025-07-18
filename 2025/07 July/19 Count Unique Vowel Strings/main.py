# Link: https://www.geeksforgeeks.org/problems/count-unique-vowel-strings/1


class Solution:
    def count(self, mask, k, freq, dp):
        if mask == (1 << k) - 1:
            return 1

        if dp[mask] != -1:
            return dp[mask]

        total = 0

        for i in range(k):
            if (mask & (1 << i)) == 0:

                total += freq[i] * self.count(mask | (1 << i), k, freq, dp)

        dp[mask] = total
        return total

    def vowelCount(self, s):
        v = "aeiou"
        f = {}

        for c in s:
            if c in v:
                f[c] = f.get(c, 0) + 1

        freq = []

        for ch in v:
            if ch in f:
                freq.append(f[ch])

        k = len(freq)
        if k == 0:
            return 0

        dp = [-1] * (1 << k)
        return self.count(0, k, freq, dp)


if __name__ == "__main__":
    sol = Solution()
    s = "aeiou"
    result = sol.vowelCount(s)
    print(result)

    s = "ae"
    result = sol.vowelCount(s)
    print(result)

    s = "aacidf"
    result = sol.vowelCount(s)
    print(result)
