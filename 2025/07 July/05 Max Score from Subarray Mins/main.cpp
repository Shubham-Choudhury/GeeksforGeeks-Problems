// Link: https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSum(vector<int> &arr)
    {
        int n = arr.size();
        int ans = 0;

        for (int i = 1; i < n; i++)
            ans = max(arr[i] + arr[i - 1], ans);

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {4, 3, 5, 1};
    int result = sol.maxSum(arr);
    cout << "Maximum sum of adjacent elements: " << result << endl;

    arr = {1, 2, 3};
    result = sol.maxSum(arr);
    cout << "Maximum sum of adjacent elements: " << result << endl;
    return 0;
}