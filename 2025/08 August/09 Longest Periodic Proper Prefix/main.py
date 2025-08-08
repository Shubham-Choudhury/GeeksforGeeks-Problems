# Link: https://www.geeksforgeeks.org/problems/longest-periodic-proper-prefix/1


class Solution:
    def zFunction(self, s):
        n = len(s)
        z = [0] * n
        l, r = 0, 0
        for i in range(1, n):
            if i <= r:
                z[i] = min(r - i + 1, z[i - l])
            while i + z[i] < n and s[z[i]] == s[i + z[i]]:
                z[i] += 1
            if i + z[i] - 1 > r:
                l = i
                r = i + z[i] - 1
        return z

    def getLongestPrefix(self, s):
        n = len(s)
        z = self.zFunction(s)

        for i in range(n - 1, 0, -1):
            if z[i] == n - i:
                return i
        return -1


if __name__ == "__main__":
    sol = Solution()
    s = "aaaaaa"
    result = sol.getLongestPrefix(s)
    print(result)

    s = "abcab"
    result = sol.getLongestPrefix(s)
    print(result)

    s = "ababd"
    result = sol.getLongestPrefix(s)
    print(result)
