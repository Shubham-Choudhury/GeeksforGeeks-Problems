// Link: https://www.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topK(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> v;
        for (auto x : mp)
        {
            v.push_back(make_pair(x.second, x.first));
        }
        sort(v.rbegin(), v.rend());
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> ans = obj.topK(nums, k);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}