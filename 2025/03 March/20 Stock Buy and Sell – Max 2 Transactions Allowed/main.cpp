// Link: https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int k = 2;
        if (n == 0 || k == 0)
            return 0;

        vector<vector<int>> curr(k + 1, vector<int>(2, 0));
        vector<vector<int>> next(k + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int l = 1; l <= k; l++)
            {
                curr[l][1] = max(-prices[i] + next[l][0], next[l][1]);
                curr[l][0] = max(prices[i] + next[l - 1][1], next[l][0]);
            }
            next = curr;
        }
        return curr[k][1];
    }
};

int main()
{
    Solution obj;
    vector<int> prices = {10, 22, 5, 75, 65, 80};
    cout << obj.maxProfit(prices) << endl;

    prices = {2, 30, 15, 10, 8, 25, 80};
    cout << obj.maxProfit(prices) << endl;
    return 0;
}