# Link: https://www.geeksforgeeks.org/problems/trail-of-ones3242/1


class Solution:
    def numberOfConsecutiveOnes(ob, n):
        mod = int(1e9 + 7)
        a, b, c = 0, 1, 0
        for i in range(2, n + 1):
            a, b, c = b, (a + b) % mod, ((c * 2) % mod + b) % mod

        return c


if __name__ == "__main__":
    obj = Solution()
    n = 2
    print(obj.numberOfConsecutiveOnes(n))
    n = 5
    print(obj.numberOfConsecutiveOnes(n))
