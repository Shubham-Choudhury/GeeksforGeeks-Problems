# Link: https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1


class Solution:
    def knapsack(self, W, val, wt):
        n = len(val)
        vec = [[-1 for _ in range(W + 1)] for _ in range(n + 1)]
        for i in range(n + 1):
            vec[i][0] = 0
        for i in range(W + 1):
            vec[0][i] = 0
        for i in range(1, n + 1):
            for j in range(1, W + 1):
                if wt[i - 1] <= j:
                    vec[i][j] = max(
                        val[i - 1] + vec[i - 1][j - wt[i - 1]], vec[i - 1][j]
                    )
                else:
                    vec[i][j] = vec[i - 1][j]
        return vec[n][W]


if __name__ == "__main__":
    obj = Solution()
    W = 4
    val = [1, 2, 3]
    wt = [4, 5, 1]
    print(obj.knapsack(W, val, wt))

    W = 3
    val = [1, 2, 3]
    wt = [4, 5, 6]
    print(obj.knapsack(W, val, wt))

    W = 5
    val = [10, 40, 30, 50]
    wt = [5, 4, 2, 3]
    print(obj.knapsack(W, val, wt))
