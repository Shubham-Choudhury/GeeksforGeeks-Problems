# Link: https://www.geeksforgeeks.org/problems/rohans-love-for-matrix4723/1


class Solution:
    def firstElement(self, n):
        mod = 1000000007
        if n == 1:
            return 1
        elif n == 2:
            return 1

        a = 1
        b = 1

        for i in range(3, n):
            t = b
            b = (a + b) % mod
            a = t

        return (a + b) % mod


if __name__ == "__main__":
    obj = Solution()
    n = 3
    print(obj.firstElement(n))
    n = 4
    print(obj.firstElement(n))
