# Link: https://www.geeksforgeeks.org/problems/sum-of-prime4751/1

import math

class Solution:
    def allPrime(self, N):
        if N < 2:
            return []

        prime = [True] * (N + 1)
        prime[0] = prime[1] = False

        limit = int(math.sqrt(N)) + 1
        for p in range(2, limit):
            if prime[p]:
                for i in range(p * p, N + 1, p):
                    prime[i] = False

        prime_numbers = [p for p in range(2, N + 1) if prime[p]]
        return prime_numbers

    def getPrimes(self, n):
        primes = self.allPrime(n)
        ans = []
        left, right = 0, len(primes) - 1
        while left <= right:
            if primes[left] + primes[right] == n:
                ans.append(primes[left])
                ans.append(primes[right])
                return ans
            elif primes[left] + primes[right] < n:
                left += 1
            else:
                right -= 1
        return ans if ans else [-1, -1]


def main():
    n = 3
    obj = Solution()
    primes = obj.getPrimes(n)
    print(*primes)

    n = 10
    primes = obj.getPrimes(n)
    print(*primes)


if __name__ == "__main__":
    main()
