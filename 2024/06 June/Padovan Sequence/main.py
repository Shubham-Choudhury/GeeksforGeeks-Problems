# Link: https://www.geeksforgeeks.org/problems/padovan-sequence2855/1


class Solution:
    def padovanSequence(self, n):
        MOD = 10**9 + 7
        p0, p1, p2 = 1, 1, 1
        if n <= 2:
            return 1
        for i in range(3, n + 1):
            p = (p1 + p0) % MOD
            p0, p1, p2 = p1, p2, p

        return p2


if __name__ == "__main__":
    obj = Solution()
    n = 3
    print(obj.padovanSequence(n))
    n = 4
    print(obj.padovanSequence(n))
