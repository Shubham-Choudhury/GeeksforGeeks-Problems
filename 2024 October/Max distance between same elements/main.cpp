// Link: https://www.geeksforgeeks.org/problems/max-distance-between-same-elements/1

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        int result = 0;

        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (mp.count(arr[i]))
            {
                result = max(result, i - mp[arr[i]]);
            }
            else
            {
                mp[arr[i]] = i;
            }
        }

        return result;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 1, 2, 2, 2, 1};
    cout << obj.maxDistance(arr) << endl;

    arr = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2};
    cout << obj.maxDistance(arr) << endl;
    return 0;
}