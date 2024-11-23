// Link: https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubarraySum(vector<int> &arr)
    {
        int maxSum = arr[0];
        int currentSum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            currentSum += arr[i];
            maxSum = max(maxSum, currentSum);
            if (currentSum < 0)
            {
                currentSum = 0;
            }
        }
        return maxSum;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << object.maxSubarraySum(arr) << endl;

    arr = {-2, -4};
    cout << object.maxSubarraySum(arr) << endl;

    arr = {5, 4, 1, 7, 8};
    cout << object.maxSubarraySum(arr) << endl;
    return 0;
}