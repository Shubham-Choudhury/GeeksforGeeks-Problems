// Link: https://www.geeksforgeeks.org/problems/subarray-range-with-given-sum0128/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subArraySum(vector<int> &arr, int tar)
    {
        unordered_map<int, int> prefixSumCount;
        int prefixSum = 0;
        int count = 0;

        prefixSumCount[0] = 1;

        for (int num : arr)
        {
            prefixSum += num;
            if (prefixSumCount.find(prefixSum - tar) != prefixSumCount.end())
            {
                count += prefixSumCount[prefixSum - tar];
            }
            prefixSumCount[prefixSum]++;
        }

        return count;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {10, 2, -2, -20, 10};
    int tar = -10;
    cout << obj.subArraySum(arr, tar) << endl;

    arr = {1, 4, 20, 3, 10, 5};
    tar = 33;
    cout << obj.subArraySum(arr, tar) << endl;
    return 0;
}