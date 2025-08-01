// Link: https://www.geeksforgeeks.org/problems/longest-subarray-with-majority-greater-than-k/1

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        int n = arr.size();
        unordered_map<int, int> mp;
        int ans = 0, sum = 0;

        for (int i = 0; i < n; ++i)
        {
            if (arr[i] <= k)
                sum--;
            else
                sum++;

            if (sum > 0)
                ans = i + 1;
            else
            {
                if (mp.find(sum - 1) != mp.end())
                {
                    ans = max(ans, i - mp[sum - 1]);
                }
            }

            if (mp.find(sum) == mp.end())
            {
                mp[sum] = i;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 1};
    int k = 2;
    int result = sol.longestSubarray(arr, k);
    cout << "Length of longest subarray with majority greater than " << k << ": " << result << endl;

    arr = {6, 5, 3, 4};
    k = 2;
    result = sol.longestSubarray(arr, k);
    cout << "Length of longest subarray with majority greater than " << k << ": " << result << endl;
    return 0;
}