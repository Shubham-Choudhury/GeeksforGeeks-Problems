// Link: https://www.geeksforgeeks.org/problems/majority-vote/1

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findMajority(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < n; i++)
            mp[arr[i]]++;
        int target = n / 3;
        for (auto it : mp)
        {
            if (it.second > target)
            {
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6};
    vector<int> ans = object.findMajority(arr);
    for (auto it : ans)
        cout << it << " ";
    cout << endl;

    arr = {1, 2, 3, 4, 5};
    ans = object.findMajority(arr);
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}