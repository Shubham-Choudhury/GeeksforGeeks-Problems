// Link: https://www.geeksforgeeks.org/problems/house-robber-ii/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int getMax(vector<int> &nums, int start, int end)
    {
        int prev = 0, prev2 = 0, curr = 0;

        for (int i = start; i <= end; ++i)
        {
            curr = max(prev, prev2 + nums[i]);
            prev2 = prev;
            prev = curr;
        }

        return curr;
    }

    int maxValue(vector<int> &arr)
    {
        int n = arr.size();
        int val1 = getMax(arr, 0, n - 2);
        int val2 = getMax(arr, 1, n - 1);
        return max(val1, val2);
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {2, 3, 2};
    cout << obj.maxValue(arr) << endl;

    arr = {1, 2, 3, 1};
    cout << obj.maxValue(arr) << endl;

    arr = {2, 2, 3, 1, 2};
    cout << obj.maxValue(arr) << endl;
    return 0;
}