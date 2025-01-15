// Link: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = -1;
        long long sum = 0;
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (mp.find(sum - k) != mp.end())
            {
                ans = max(ans, i - mp[sum - k]);
            }
            if (mp.find(sum) == mp.end())
                mp[sum] = i;
        }
        return ans;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    int k = 15;
    cout << object.longestSubarray(arr, k) << endl;

    arr = {-5, 8, -14, 2, 4, 12};
    k = -5;
    cout << object.longestSubarray(arr, k) << endl;

    arr = {10, -10, 20, 30};
    k = 5;
    cout << object.longestSubarray(arr, k) << endl;
    return 0;
}