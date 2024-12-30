// Link: https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    long long getCount(int n)
    {
        vector<vector<int>> neighbors = {
            {0, 8},
            {1, 2, 4},
            {2, 1, 3, 5},
            {3, 2, 6},
            {4, 1, 5, 7},
            {5, 2, 4, 6, 8},
            {6, 3, 5, 9},
            {7, 4, 8},
            {8, 0, 5, 7, 9},
            {9, 6, 8}};

        if (n == 1)
            return 10;

        vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));

        for (int i = 0; i < 10; ++i)
        {
            dp[1][i] = 1;
        }

        for (int len = 2; len <= n; ++len)
        {
            for (int digit = 0; digit < 10; ++digit)
            {
                dp[len][digit] = 0;
                for (int neighbor : neighbors[digit])
                {
                    dp[len][digit] += dp[len - 1][neighbor];
                }
            }
        }

        long long totalCount = 0;
        for (int i = 0; i < 10; ++i)
        {
            totalCount += dp[n][i];
        }

        return totalCount;
    }
};

int main()
{
    Solution obj;
    cout << obj.getCount(1) << endl;
    cout << obj.getCount(2) << endl;
    return 0;
}
