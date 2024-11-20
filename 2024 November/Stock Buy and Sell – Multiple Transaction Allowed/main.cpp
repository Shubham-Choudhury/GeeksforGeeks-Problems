// Link: https://www.geeksforgeeks.org/problems/stock-buy-and-sell2615/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maximumProfit(vector<int> &prices)
    {
        int buyPrice{prices[0]};
        int profit{0};
        for (int price : prices)
        {
            if (buyPrice < price)
                profit += price - buyPrice;
            buyPrice = price;
        }
        return profit;
    }
};

int main()
{
    Solution object;
    vector<int> prices{100, 180, 260, 310, 40, 535, 695};
    cout << object.maximumProfit(prices) << endl;

    prices = {4, 2, 2, 2, 4};
    cout << object.maximumProfit(prices) << endl;
    return 0;
}