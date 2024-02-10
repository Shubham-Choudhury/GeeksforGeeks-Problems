// Link: https://www.geeksforgeeks.org/problems/number-of-paths-in-a-matrix-with-k-coins2728/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(vector<vector<int>> &arr, int i, int j, int k, int n, vector<vector<vector<int>>> &dp)
    {
        if (i == n - 1 and j == n - 1)
            return k == arr[i][j];
        if (i < 0 || j < 0 || i >= n || j >= n || k <= 0)
            return 0;
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        return dp[i][j][k] = solve(arr, i, j + 1, k - arr[i][j], n, dp) + solve(arr, i + 1, j, k - arr[i][j], n, dp);
    }
    long long numberOfPath(int n, int k, vector<vector<int>> arr)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        return solve(arr, 0, 0, k, n, dp);
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> arr = {{1, 2, 3}, {4, 6, 5}, {3, 2, 1}};
    cout << obj.numberOfPath(3, 12, arr) << endl;
    return 0;
}