// Link: https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int countSubarrays(vector<int> &arr, int k)
    {
        unordered_map<int, int> prefixSumCount;
        int currentSum = 0;
        int count = 0;

        prefixSumCount[0] = 1;

        for (int num : arr)
        {
            currentSum += num;
            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end())
            {
                count += prefixSumCount[currentSum - k];
            }
            prefixSumCount[currentSum]++;
        }
        return count;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {10, 2, -2, -20, 10};
    int k = -10;
    cout << object.countSubarrays(arr, k) << endl;

    arr = {9, 4, 20, 3, 10, 5};
    k = 33;
    cout << object.countSubarrays(arr, k) << endl;

    arr = {1, 3, 5};
    k = 0;
    cout << object.countSubarrays(arr, k) << endl;
    return 0;
}