// Link: https://www.geeksforgeeks.org/problems/dice-throw5349/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int noOfWays(int m, int n, int x)
    {
        vector<int> dp(x + 1, 0);

        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = x; j >= 1; j--)
            {
                dp[j] = 0;
                for (int k = 1; k <= m && j - k >= 0; k++)
                {
                    dp[j] += dp[j - k];
                }
            }
            dp[0] = 0;
        }
        return dp[x];
    }
};

int main()
{
    Solution sol;
    int m = 6;
    int n = 3;
    int x = 12;
    cout << "Number of ways to get sum " << x << " with " << n << " dice: " << sol.noOfWays(m, n, x) << endl;

    m = 2;
    n = 3;
    x = 6;
    cout << "Number of ways to get sum " << x << " with " << n << " dice: " << sol.noOfWays(m, n, x) << endl;
    return 0;
}