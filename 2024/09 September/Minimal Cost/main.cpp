// Link: https://www.geeksforgeeks.org/problems/minimal-cost/1

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int minimizeCost(int k, vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, 0);

        dp[0] = 0;

        for (int i = 1; i < n; i++)
        {
            int minSteps = INT_MAX;

            for (int j = 1; j <= k; j++)
            {
                if (i - j >= 0)
                {
                    int jump = dp[i - j] + abs(arr[i] - arr[i - j]);
                    minSteps = min(minSteps, jump);
                }
            }

            dp[i] = minSteps;
        }

        return dp[n - 1];
    }
};

int main()
{
    Solution obj;
    int k = 3;
    vector<int> arr = {10, 30, 40, 50, 20};
    cout << obj.minimizeCost(k, arr) << endl;

    k = 1;
    arr = {10, 20, 10};
    return 0;
}