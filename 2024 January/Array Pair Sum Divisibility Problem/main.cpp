// Link: https://www.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPair(vector<int> nums, int k)
    {
        int n = nums.size();
        if (n % 2 == 1)
            return false;

        map<int, int> mp;
        int ans = 0;

        for (auto &it : nums)
        {
            it = it % k;
        }

        for (int i = 0; i < n; i++)
        {
            int newVal = k - nums[i];

            if (nums[i] == 0 && mp.find(0) != mp.end())
            {
                ans++;
                mp.erase(0);
                continue;
            }

            if (mp.find(newVal) != mp.end())
            {
                ans++;
                mp.erase(newVal);
            }
            else
            {
                mp[nums[i]]++;
            }
        }
        return ans == (n / 2);
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {9, 5, 7, 3};
    int k = 4;
    cout << obj.canPair(nums, k) << endl;
    return 0;
}