# Link: https://www.geeksforgeeks.org/problems/equalize-the-towers2804/1


class Solution:
    def costOfOperation(self, heights, cost, targetHeight):
        totalCost = 0
        for i in range(len(heights)):
            totalCost += abs(heights[i] - targetHeight) * cost[i]
        return totalCost

    def minCost(self, heights, cost):
        max_h = max(heights)
        minCost = float("inf")

        low, high = 0, max_h
        while low <= high:
            mid = (low + high) // 2

            costAtMid = self.costOfOperation(heights, cost, mid)
            costAtMidMinus1 = (
                self.costOfOperation(heights, cost, mid - 1)
                if mid > 0
                else float("inf")
            )
            costAtMidPlus1 = self.costOfOperation(heights, cost, mid + 1)

            minCost = min(minCost, costAtMid)

            if costAtMidMinus1 <= costAtMid:
                high = mid - 1
            elif costAtMidPlus1 <= costAtMid:
                low = mid + 1
            else:
                break

        return minCost


if __name__ == "__main__":
    obj = Solution()
    heights = [1, 2, 3]
    cost = [10, 100, 1000]
    result = obj.minCost(heights, cost)
    print(f"Minimum cost to equalize towers: {result}")

    heights = [7, 1, 5]
    cost = [1, 1, 1]
    result = obj.minCost(heights, cost)
    print(f"Minimum cost to equalize towers: {result}")
