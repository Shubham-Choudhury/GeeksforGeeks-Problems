// Link: https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> minMaxCandy(vector<int> &prices, int k)
    {
        sort(prices.begin(), prices.end());
        int n = prices.size();

        int minCost = 0;
        int i = 0, remaining = n;
        while (i < remaining)
        {
            minCost += prices[i];
            i++;
            remaining -= k;
        }

        int maxCost = 0;
        int j = n - 1, index = -1;
        while (j > index)
        {
            maxCost += prices[j];
            j--;
            index += k;
        }

        return {minCost, maxCost};
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {1, 2, 3, 4, 5};
    int k = 2;
    vector<int> result = sol.minMaxCandy(prices, k);
    cout << "Minimum Cost: " << result[0] << " Maximum Cost: " << result[1] << endl;

    prices = {3, 2, 1, 4, 5};
    k = 4;
    result = sol.minMaxCandy(prices, k);
    cout << "Minimum Cost: " << result[0] << " Maximum Cost: " << result[1] << endl;
    return 0;
}