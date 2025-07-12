// Link: https://www.geeksforgeeks.org/problems/maximum-sum-of-elements-not-part-of-lis/1

#include <iostream>
#include <vector>
#include <map>
#include <numeric>
using namespace std;

class Solution
{
public:
    map<int, vector<int>> mp;
    void insert(int val)
    {
        auto it = mp.lower_bound(val);

        int len = 1;
        int sum = val;

        if (it != mp.begin())
        {
            auto prev = it;
            --prev;
            len = prev->second[0] + 1;
            sum = prev->second[1] + val;
        }

        vector<int> toerase;
        while (it != mp.end())
        {
            if (it->second[0] > len)
                break;
            toerase.push_back(it->first);
            ++it;
        }

        for (int key : toerase)
        {
            mp.erase(key);
        }

        mp[val] = {len, sum};
    }

    int nonLisMaxSum(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            insert(arr[i]);
        }

        auto last = --mp.end();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int lisSum = last->second[1];

        return totalSum - lisSum;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {4, 6, 1, 2, 3, 8};
    int result = sol.nonLisMaxSum(arr);
    cout << "Maximum sum of elements not part of LIS is " << result << endl;

    arr = {5, 4, 3, 2, 1};
    result = sol.nonLisMaxSum(arr);
    cout << "Maximum sum of elements not part of LIS is " << result << endl;

    return 0;
}