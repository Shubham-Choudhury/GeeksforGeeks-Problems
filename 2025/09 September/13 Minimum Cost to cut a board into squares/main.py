# Link: https://www.geeksforgeeks.org/problems/minimum-cost-to-cut-a-board-into-squares/1


class Solution:
    def minCost(self, n, m, x, y):
        x.sort()
        y.sort()

        hCount, vCount = 1, 1
        i, j = len(x) - 1, len(y) - 1
        totalCost = 0
        while i >= 0 and j >= 0:
            if x[i] >= y[j]:
                totalCost += x[i] * hCount
                vCount += 1
                i -= 1
            else:
                totalCost += y[j] * vCount
                hCount += 1
                j -= 1

        while i >= 0:
            totalCost += x[i] * hCount
            vCount += 1
            i -= 1

        while j >= 0:
            totalCost += y[j] * vCount
            hCount += 1
            j -= 1

        return totalCost


if __name__ == "__main__":
    sol = Solution()
    n, m = 4, 6
    x = [2, 1, 3, 1, 4]
    y = [4, 1, 2]
    result = sol.minCost(n, m, x, y)
    print(f"Minimum cost to cut the board into squares: {result}")

    n, m = 4, 4
    x = [1, 1, 1]
    y = [1, 1, 1]
    result = sol.minCost(n, m, x, y)
    print(f"Minimum cost to cut the board into squares: {result}")
