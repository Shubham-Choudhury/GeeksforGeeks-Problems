// Link: https://www.geeksforgeeks.org/problems/sum-of-subarrays2229/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &arr)
    {
        int n = arr.size();
        int result = 0;

        for (int i = 0; i < n; i++)
            result += (arr[i] * (i + 1) * (n - i));

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3};
    int result = sol.subarraySum(arr);
    cout << "Sum of all subarrays: " << result << endl;

    arr = {1, 3};
    result = sol.subarraySum(arr);
    cout << "Sum of all subarrays: " << result << endl;

    return 0;
}