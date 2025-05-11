// Link: https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int kthLargest(vector<int> &arr, int k)
    {

        int n = arr.size();

        vector<int> prefixSum(n + 1);
        prefixSum[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
        }

        vector<int> subarraySums;
        for (int i = 0; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                subarraySums.push_back(prefixSum[j] - prefixSum[i]);
            }
        }

        sort(subarraySums.begin(), subarraySums.end(),
             greater<int>());

        return subarraySums[k - 1];
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {3, 2, 1};
    int k = 2;
    cout << "The " << k << "th largest sum of contiguous subarray is: " << sol.kthLargest(arr, k) << endl;

    arr = {2, 6, 4, 1};
    k = 3;
    cout << "The " << k << "th largest sum of contiguous subarray is: " << sol.kthLargest(arr, k) << endl;
    return 0;
}