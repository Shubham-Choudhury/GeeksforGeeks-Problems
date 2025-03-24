// Link: https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int matrixMultiplication(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int l = 2; l < n; ++l)
        {
            for (int i = 1; i < n - l + 1; ++i)
            {
                int j = i + l - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; ++k)
                {
                    int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[1][n - 1];
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {2, 1, 3, 4};
    cout << obj.matrixMultiplication(arr) << endl;

    arr = {1, 2, 3, 4, 3};
    cout << obj.matrixMultiplication(arr) << endl;

    arr = {3, 4};
    cout << obj.matrixMultiplication(arr) << endl;
    return 0;
}