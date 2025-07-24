// Link: https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxCircularSum(vector<int> &arr)
    {
        int totalSum = 0;
        int currMaxSum = 0, currMinSum = 0;
        int maxSum = arr[0], minSum = arr[0];

        for (int i = 0; i < arr.size(); i++)
        {
            currMaxSum = max(currMaxSum + arr[i], arr[i]);
            maxSum = max(maxSum, currMaxSum);

            currMinSum = min(currMinSum + arr[i], arr[i]);
            minSum = min(minSum, currMinSum);

            totalSum = totalSum + arr[i];
        }

        int normalSum = maxSum;
        int circularSum = totalSum - minSum;

        if (minSum == totalSum)
            return normalSum;

        return max(normalSum, circularSum);
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    cout << "Maximum Circular Subarray Sum: " << sol.maxCircularSum(arr) << endl;

    arr = {10, -3, -4, 7, 6, 5, -4, -1};
    cout << "Maximum Circular Subarray Sum: " << sol.maxCircularSum(arr) << endl;

    arr = {5, -2, 3, 4};
    cout << "Maximum Circular Subarray Sum: " << sol.maxCircularSum(arr) << endl;
    return 0;
}