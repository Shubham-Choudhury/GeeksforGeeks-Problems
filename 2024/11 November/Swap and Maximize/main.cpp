// Link: https://www.geeksforgeeks.org/problems/swap-and-maximize5859/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maxSum(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        vector<long long> ans;
        int n = arr.size();
        int i = 0, j = n - 1;
        while (i <= j)
        {
            if (i == j)
                ans.push_back(arr[i]);
            else
            {
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
            }
            i++;
            j--;
        }
        long long sum = 0;
        for (int i = 1; i < n; i++)
        {
            sum += abs(ans[i] - ans[i - 1]);
        }
        sum += abs(ans[n - 1] - ans[0]);
        return sum;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {4, 2, 1, 8};
    cout << object.maxSum(arr) << endl;

    arr = {10, 12};
    cout << object.maxSum(arr) << endl;
    return 0;
}