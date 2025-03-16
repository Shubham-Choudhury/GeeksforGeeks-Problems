// Link: https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool subsetSumHelper(vector<int> &arr, int sum, int n, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return true;
        if (n == 0)
            return false;

        if (dp[n][sum] != -1)
            return dp[n][sum];

        if (arr[n - 1] > sum)
            return dp[n][sum] = subsetSumHelper(arr, sum, n - 1, dp);

        return dp[n][sum] = subsetSumHelper(arr, sum - arr[n - 1], n - 1, dp) ||
                            subsetSumHelper(arr, sum, n - 1, dp);
    }

    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return subsetSumHelper(arr, sum, n, dp);
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    cout << boolalpha << obj.isSubsetSum(arr, sum) << endl;

    arr = {3, 34, 4, 12, 5, 2};
    sum = 30;
    cout << boolalpha << obj.isSubsetSum(arr, sum) << endl;

    arr = {1, 2, 3};
    sum = 6;
    cout << boolalpha << obj.isSubsetSum(arr, sum) << endl;
    return 0;
}