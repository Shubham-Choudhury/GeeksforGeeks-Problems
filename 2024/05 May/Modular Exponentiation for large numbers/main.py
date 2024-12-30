# Link: https://www.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1


class Solution:
    def PowMod(self, x, n, m):
        if n == 0:
            return 1
        elif n % 2 == 0:
            return self.PowMod((x * x) % m, n // 2, m)
        else:
            return (x * self.PowMod((x * x) % m, (n - 1) // 2, m)) % m


if __name__ == "__main__":
    obj = Solution()
    x = 3
    n = 2
    m = 4
    print(obj.PowMod(x, n, m))

    x = 2
    n = 6
    m = 10
    print(obj.PowMod(x, n, m))
