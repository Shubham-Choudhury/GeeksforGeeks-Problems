# Link: https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution:
    def solve(self, W, wt, val, sum, n, i):
        if i >= n:
            return sum
        if W - wt[i] >= 0:
            taken = self.solve(W - wt[i], wt, val, sum + val[i], n, i + 1)
            notTaken = self.solve(W, wt, val, sum, n, i + 1)
            return max(taken, notTaken)
        else:
            notTaken = self.solve(W, wt, val, sum, n, i + 1)
            return max(sum, notTaken)

    def knapSack(self, W, wt, val):
        sum = 0
        n = len(wt)
        taken = self.solve(W, wt, val, sum, n, 0)
        notTaken = self.solve(W, wt, val, sum, n, 1)
        return max(taken, notTaken)


if __name__ == "__main__":
    obj = Solution()
    wt = [4, 5, 1]
    val = [1, 2, 3]
    W = 4
    print(obj.knapSack(W, wt, val))

    wt = [4, 5, 6]
    val = [1, 2, 3]
    W = 3
    print(obj.knapSack(W, wt, val))
