# Link: https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1


class Solution:
    def minMaxCandy(self, prices, k):
        prices.sort()
        n = len(prices)

        minCost = 0
        i = 0
        remaining = n
        while i < remaining:
            minCost += prices[i]
            i += 1
            remaining -= k

        maxCost = 0
        i = n - 1
        index = -1
        while i > index:
            maxCost += prices[i]
            i -= 1
            index += k

        return [minCost, maxCost]


if __name__ == "__main__":
    sol = Solution()
    prices = [3, 2, 1, 4]
    k = 2
    result = sol.minMaxCandy(prices, k)
    print(f"Minimum Cost: {result[0]}, Maximum Cost: {result[1]}")

    prices = [3, 2, 1, 4, 5]
    k = 4
    result = sol.minMaxCandy(prices, k)
    print(f"Minimum Cost: {result[0]}, Maximum Cost: {result[1]}")
