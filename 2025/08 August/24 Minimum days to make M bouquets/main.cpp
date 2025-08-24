// Link: https://www.geeksforgeeks.org/problems/minimum-days-to-make-m-bouquets/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &arr, int k, int m, int days)
    {
        int bouquets = 0;
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= days)
            {
                cnt += 1;
            }
            else
            {
                bouquets += cnt / k;
                cnt = 0;
            }
        }

        bouquets += cnt / k;
        return bouquets >= m;
    }

    int minDaysBloom(vector<int> &arr, int k, int m)
    {
        int lo = 0;
        int hi = *max_element(arr.begin(), arr.end());
        int res = -1;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;

            if (check(arr, k, m, mid))
            {
                res = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {3, 4, 2, 7, 13, 8, 5};
    int m = 3, k = 2;
    int result = sol.minDaysBloom(arr, k, m);
    cout << "The minimum number of days to make " << m << " bouquets is: " << result << endl;

    arr = {5, 5, 5, 5, 10, 5, 5};
    m = 2, k = 3;
    result = sol.minDaysBloom(arr, k, m);
    cout << "The minimum number of days to make " << m << " bouquets is: " << result << endl;

    arr = {1, 10, 3, 10, 2};
    m = 3, k = 2;
    result = sol.minDaysBloom(arr, k, m);
    cout << "The minimum number of days to make " << m << " bouquets is: " << result << endl;
    return 0;
}