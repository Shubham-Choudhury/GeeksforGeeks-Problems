// Link: https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool equalPartition(vector<int> &arr)
    {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
            sum += arr[i];
        if (sum % 2 != 0)
            return false;
        sum /= 2;
        vector<vector<bool>> dp(arr.size() + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= arr.size(); i++)
            dp[i][0] = true;
        for (int i = 1; i <= arr.size(); i++)
            for (int j = 1; j <= sum; j++)
                if (j >= arr[i - 1])
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
        return dp[arr.size()][sum];
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 5, 11, 5};
    cout << boolalpha << obj.equalPartition(arr) << endl;

    arr = {1, 3, 5};
    cout << boolalpha << obj.equalPartition(arr) << endl;
    return 0;
}