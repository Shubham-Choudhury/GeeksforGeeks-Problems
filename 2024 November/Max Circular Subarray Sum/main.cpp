// Link: https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int circularSubarraySum(vector<int> &arr)
    {
        int n = arr.size();
        int maxsum = INT_MIN, sum = 0;
        int totalsum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            totalsum += arr[i];
            maxsum = max(maxsum, sum);
            if (sum < 0)
            {
                sum = 0;
            }
        }

        int minsum = INT_MAX, sum1 = 0;
        for (int i = 0; i < n; i++)
        {
            sum1 += arr[i];
            minsum = min(minsum, sum1);
            if (sum1 > 0)
            {
                sum1 = 0;
            }
        }
        if (maxsum < 0)
        {
            return maxsum;
        }
        return max(maxsum, totalsum - minsum);
    }
};

int main()
{
    Solution object;
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    cout << object.circularSubarraySum(arr) << endl;

    arr = {10, -3, -4, 7, 6, 5, -4, -1};
    cout << object.circularSubarraySum(arr) << endl;

    arr = {-1, 40, -14, 7, 6, 5, -4, -1};
    cout << object.circularSubarraySum(arr) << endl;
    return 0;
}