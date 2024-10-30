// Link: https://www.geeksforgeeks.org/problems/pairs-with-difference-k1713/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int countPairsWithDiffK(vector<int> &arr, int k)
    {
        int ans = 0;
        unordered_map<int, int> mp;

        for (auto x : arr)
        {
            ans += mp[x - k];
            ans += mp[x + k];

            mp[x]++;
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 5, 3, 4, 2};
    int k = 3;
    cout << obj.countPairsWithDiffK(arr, k) << endl;

    arr = {8, 12, 16, 4, 0, 20};
    k = 4;
    cout << obj.countPairsWithDiffK(arr, k) << endl;
    return 0;
}