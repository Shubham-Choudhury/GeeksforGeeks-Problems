# Link: https://www.geeksforgeeks.org/problems/buy-stock-2/1


class Solution:
    def maximumProfit(self, prices):
        N = len(prices)
        init = prices[0]
        max_price = float("-inf")
        res = 0

        for i in range(N):
            if prices[i] >= init and prices[i] > max_price:
                max_price = max(max_price, prices[i])
            elif prices[i] < init:
                res = max(res, (max_price - init))
                init = prices[i]
                max_price = prices[i]

        res = max(res, (max_price - init))

        return res


if __name__ == "__main__":
    object = Solution()
    prices = [7, 10, 1, 3, 6, 9, 2]
    print(object.maximumProfit(prices))

    prices = [7, 6, 4, 3, 1]
    print(object.maximumProfit(prices))

    prices = [1, 3, 6, 9, 11]
    print(object.maximumProfit(prices))
