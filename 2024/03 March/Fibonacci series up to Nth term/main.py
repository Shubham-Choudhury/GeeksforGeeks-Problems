# Link: https://www.geeksforgeeks.org/problems/fibonacci-series-up-to-nth-term/1


class Solution:
    def series(self, n):
        a = 0
        b = 1
        fibo = []
        fibo.append(a)
        fibo.append(b)
        for i in range(0, n - 1):
            c = fibo[i] + fibo[i + 1]
            fibo.append(c % (10**9 + 7))

        return fibo


if __name__ == "__main__":
    obj = Solution()
    n = 5
    print(obj.series(n))
    n = 10
    print(obj.series(n))
