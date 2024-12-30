# Link: https://www.geeksforgeeks.org/problems/stock-buy-and-sell2615/1


class Solution:
    def maximumProfit(self, prices) -> int:
        buy_price = prices[0]
        profit = 0
        for price in prices:
            if buy_price < price:
                profit += price - buy_price
            buy_price = price
        return profit


if __name__ == "__main__":
    obj = Solution()
    prices = [100, 180, 260, 310, 40, 535, 695]
    print(obj.maximumProfit(prices))

    prices = [4, 2, 2, 2, 4]
    print(obj.maximumProfit(prices))
