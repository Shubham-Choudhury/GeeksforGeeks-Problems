// Link: https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPartitions(int n, int d, vector<int> &arr)
    {
        int totsum = accumulate(arr.begin(), arr.end(), 0);
        if (totsum - d < 0 || (totsum - d) % 2 != 0)
        {
            return 0;
        }
        else
        {
            int k = (totsum - d) / 2;
            vector<vector<int>> dp(n, vector<int>(k + 1, 0));
            if (arr[0] == 0)
            {
                dp[0][0] = 2;
            }
            else
            {
                dp[0][0] = 1;
            }
            if (arr[0] != 0 && arr[0] <= k)
            {
                dp[0][arr[0]] = 1;
            }
            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j <= k; j++)
                {
                    int notpick = dp[i - 1][j];
                    int pick = 0;
                    if (arr[i] <= j)
                    {
                        pick = dp[i - 1][j - arr[i]];
                    }
                    dp[i][j] = (pick + notpick) % static_cast<int>(1e9 + 7);
                }
            }
            return dp[n - 1][k];
        }
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {5, 2, 6, 4};
    int n = arr.size();
    int d = 3;
    cout << obj.countPartitions(n, d, arr) << endl;

    arr = {1, 1, 1, 1};
    n = arr.size();
    d = 0;
    cout << obj.countPartitions(n, d, arr) << endl;

    return 0;
}
