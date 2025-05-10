// Link: https://www.geeksforgeeks.org/problems/longest-subarray-with-majority-greater-than-k/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        int n = arr.size();
        unordered_map<int, int> prefIdx;
        int sum = 0, res = 0;

        for (int i = 0; i < n; i++)
        {

            sum += (arr[i] > k ? 1 : -1);

            if (prefIdx.find(sum) == prefIdx.end())
                prefIdx[sum] = i;
        }

        if (prefIdx.find(-n) != prefIdx.end())
            return 0;

        prefIdx[-n] = n;

        for (int i = -n + 1; i <= n; i++)
        {
            if (prefIdx.find(i) == prefIdx.end())
                prefIdx[i] = prefIdx[i - 1];
            else
                prefIdx[i] = min(prefIdx[i], prefIdx[i - 1]);
        }

        sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += (arr[i] > k ? 1 : -1);
            if (sum > 0)
                res = i + 1;
            else
                res = max(res, i - prefIdx[sum - 1]);
        }
        return res;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 1};
    int k = 2;
    cout << obj.longestSubarray(arr, k) << endl;

    arr = {6, 5, 3, 4};
    k = 2;
    cout << obj.longestSubarray(arr, k) << endl;

    return 0;
}