# Link: https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter5639/1


class Solution:
    def nthStair(self, n):
        if n == 1:
            return 1
        f = [0] * (n + 1)
        f[1] = 1
        f[2] = 2
        for i in range(3, n + 1):
            if i % 2 == 0:
                f[i] = f[i - 2] + 1
            else:
                f[i] = f[i - 1]
        return f[n]


if __name__ == "__main__":
    obj = Solution()
    n = 4
    print(obj.nthStair(n))
    n = 5
    print(obj.nthStair(n))
