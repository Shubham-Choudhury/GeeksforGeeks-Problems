// Link: https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int cntSubarrays(vector<int> &arr, int k)
    {
        unordered_map<int, int> prefixSums;

        int res = 0;
        int currSum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            currSum += arr[i];
            if (currSum == k)
                res++;

            if (prefixSums.find(currSum - k) != prefixSums.end())
                res += prefixSums[currSum - k];

            prefixSums[currSum]++;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {10, 2, -2, -20, 10};
    int k = -10;
    int result = sol.cntSubarrays(arr, k);
    cout << "Number of subarrays with sum " << k << ": " << result << endl;

    arr = {9, 4, 20, 3, 10, 5};
    k = 33;
    result = sol.cntSubarrays(arr, k);
    cout << "Number of subarrays with sum " << k << ": " << result << endl;

    arr = {1, 3, 5};
    k = 0;
    result = sol.cntSubarrays(arr, k);
    cout << "Number of subarrays with sum " << k << ": " << result << endl;

    return 0;
}