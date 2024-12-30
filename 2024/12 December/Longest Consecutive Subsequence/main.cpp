// Link: https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            int x = arr[i];
            if (mp[x - 1] == 0)
            {
                while (mp[x] != 0)
                    x++;

                ans = max(ans, x - arr[i]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {2, 6, 1, 9, 4, 5, 3};
    cout << object.longestConsecutive(arr) << endl;

    arr = {1, 9, 3, 10, 4, 20, 2};
    cout << object.longestConsecutive(arr) << endl;

    arr = {15, 13, 12, 14, 11, 10, 9};
    cout << object.longestConsecutive(arr) << endl;
    return 0;
}