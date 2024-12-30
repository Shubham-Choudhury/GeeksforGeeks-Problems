// Link: https://www.geeksforgeeks.org/problems/buy-stock-2/1

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
#define MAX(A, B) (A > B ? A : B)
    int maximumProfit(vector<int> &prices)
    {
        int i, N = prices.size();
        int init = prices[0];
        int max = INT_MIN;
        int res = 0;

        for (i = 0; i < N; i++)
        {
            if ((prices[i] >= init) && (prices[i] > max))
            {
                max = MAX(max, prices[i]);
            }
            else if (prices[i] < init)
            {
                res = MAX(res, (max - init));
                init = prices[i];
                max = prices[i];
            }
        }

        res = MAX(res, (max - init));

        return res;
    }
};

int main()
{
    Solution object;
    vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
    cout << object.maximumProfit(prices) << endl;

    prices = {7, 6, 4, 3, 1};
    cout << object.maximumProfit(prices) << endl;

    prices = {1, 3, 6, 9, 11};
    cout << object.maximumProfit(prices) << endl;
    return 0;
}