// Link: https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<long long int> productExceptSelf(vector<long long int> &nums)
    {
        int n = nums.size();
        vector<long long int> result(n, 1);
        long long int left = 1, right = 1;
        for (int i = 0; i < n; i++)
        {
            result[i] *= left;
            result[n - i - 1] *= right;
            left *= nums[i];
            right *= nums[n - i - 1];
        }
        return result;
    }
};

int main()
{
    Solution obj;
    vector<long long int> nums = {10, 3, 5, 6, 2};
    vector<long long int> ans = obj.productExceptSelf(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    nums = {12, 0};
    ans = obj.productExceptSelf(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}