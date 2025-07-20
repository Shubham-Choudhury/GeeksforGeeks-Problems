# Link: https://www.geeksforgeeks.org/problems/count-the-coprimes/1


class Solution:
    def computeMobius(self, n, mu):
        is_prime = [1] * (n + 1)
        mu[0] = 0
        mu[1] = 1

        for i in range(2, n + 1):
            if is_prime[i]:
                for j in range(i, n + 1, i):
                    mu[j] *= -1
                    is_prime[j] = 0
                for j in range(i * i, n + 1, i * i):
                    mu[j] = 0

    def buildFre(self, arr, freq):
        for x in arr:
            freq[x] += 1

    def computeDivCnt(self, maxVal, freq, d):
        for k in range(1, maxVal + 1):
            for j in range(k, maxVal + 1, k):
                d[k] += freq[j]

    def cntCoprime(self, arr):
        maxVal = max(arr)
        freq = [0] * (maxVal + 1)
        d = [0] * (maxVal + 1)
        mu = [1] * (maxVal + 1)

        self.buildFre(arr, freq)
        self.computeDivCnt(maxVal, freq, d)
        self.computeMobius(maxVal, mu)

        result = 0
        for k in range(1, maxVal + 1):
            if mu[k] == 0 or d[k] < 2:
                continue

            pairs = d[k] * (d[k] - 1) // 2
            result += mu[k] * pairs

        return result


if __name__ == "__main__":
    sol = Solution()
    arr = [1, 2, 3]
    result = sol.cntCoprime(arr)
    print(f"Count of coprime pairs: {result}")

    arr = [4, 8, 3, 9]
    result = sol.cntCoprime(arr)
    print(f"Count of coprime pairs: {result}")
