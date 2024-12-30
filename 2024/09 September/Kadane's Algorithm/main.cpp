// Link: https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    long long maxSubarraySum(vector<int> &arr)
    {
        long long sum = 0;
        long long ans = arr[0];

        for (int i : arr)
        {
            sum += i;
            ans = max(ans, sum);
            if (sum < 0)
            {
                sum = 0;
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 3, -2, 5};
    cout << obj.maxSubarraySum(arr) << endl;
    arr = {-1, -2, -3, -4};
    cout << obj.maxSubarraySum(arr) << endl;
    arr = {5, 4, 7};
    cout << obj.maxSubarraySum(arr) << endl;
    return 0;
}