# Link: https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1


class Solution:
    def countWaysRec(self, n, memo):
        if n == 0 or n == 1:
            return 1

        if memo[n] != -1:
            return memo[n]

        memo[n] = self.countWaysRec(n - 1, memo) + self.countWaysRec(n - 2, memo)
        return memo[n]

    def countWays(self, n):
        memo = [-1] * (n + 1)
        return self.countWaysRec(n, memo)


if __name__ == "__main__":
    obj = Solution()
    n = 1
    print(obj.countWays(n))

    n = 2
    print(obj.countWays(n))

    n = 4
    print(obj.countWays(n))
