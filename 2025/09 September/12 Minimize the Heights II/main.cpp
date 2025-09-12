// Link: https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int getMinDiff(vector<int> &arr, int k)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int res = arr[n - 1] - arr[0];

        for (int i = 1; i < n; i++)
        {
            if (arr[i] - k < 0)
                continue;

            int minH = min(arr[0] + k, arr[i] - k);
            int maxH = max(arr[i - 1] + k, arr[n - 1] - k);
            res = min(res, maxH - minH);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 5, 8, 10};
    int k = 2;
    int result = sol.getMinDiff(arr, k);
    cout << "The minimized maximum difference is: " << result << endl;

    arr = {3, 9, 12, 16, 20};
    k = 3;
    result = sol.getMinDiff(arr, k);
    cout << "The minimized maximum difference is: " << result << endl;

    return 0;
}