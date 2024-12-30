// Link: https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(int i, int j, int arr[], vector<vector<long long>> &dp)
    {
        if (j < i)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int left = 1e9, right = 1e9;

        left = arr[i] + min(solve(i + 2, j, arr, dp), solve(i + 1, j - 1, arr, dp));
        right = arr[j] + min(solve(i + 1, j - 1, arr, dp), solve(i, j - 2, arr, dp));

        return dp[i][j] = max(left, right);
    }

    long long maximumAmount(int n, int arr[])
    {
        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        return solve(0, n - 1, arr, dp);
    }
};

int main()
{
    Solution obj;
    int arr1[] = {5, 3, 7, 10};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << obj.maximumAmount(n1, arr1) << endl;
    int arr2[] = {8, 15, 3, 7};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << obj.maximumAmount(n2, arr2) << endl;
    return 0;
}