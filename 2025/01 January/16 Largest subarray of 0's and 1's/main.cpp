// Link: https://www.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxLen(vector<int> &arr)
    {
        int maxLen = 0;
        unordered_map<int, int> mp;
        int presum = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            presum += (arr[i] == 0) ? -1 : 1;
            if (presum == 0)
                maxLen = i + 1;
            if (mp.find(presum) != mp.end())
                maxLen = max(maxLen, i - mp[presum]);
            else
                mp[presum] = i;
        }
        return maxLen;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {1, 0, 1, 1, 1, 0, 0};
    cout << object.maxLen(arr) << endl;

    arr = {0, 0, 1, 1, 0};
    cout << object.maxLen(arr) << endl;

    arr = {0};
    cout << object.maxLen(arr) << endl;
    return 0;
}