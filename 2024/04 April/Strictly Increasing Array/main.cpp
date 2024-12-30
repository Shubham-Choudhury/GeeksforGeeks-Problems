// Link: https://www.geeksforgeeks.org/problems/convert-to-strictly-increasing-array3351/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int min_operations(vector<int> &nums)
    {
        int n = nums.size(), ans = 1;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (i - j <= nums[i] - nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return n - ans;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 2, 6, 5, 4};
    cout << obj.min_operations(nums) << endl;
    nums = {1, 1, 1, 1};
    cout << obj.min_operations(nums) << endl;
    return 0;
}