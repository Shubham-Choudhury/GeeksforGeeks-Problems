// Link: https://www.geeksforgeeks.org/problems/maximize-median-after-doing-k-addition-operation/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &arr, int target, int k)
    {
        int n = arr.size();

        if (n % 2 == 1)
        {
            for (int i = n / 2; i < n; ++i)
            {
                if (arr[i] < target)
                    k -= (target - arr[i]);
            }
        }
        else
        {
            if (arr[n / 2] <= target)
            {
                k -= (target - arr[n / 2]);
                k -= (target - arr[n / 2 - 1]);
            }
            else
            {
                k -= (2 * target -
                      (arr[n / 2] + arr[n / 2 - 1]));
            }
            for (int i = n / 2 + 1; i < n; ++i)
            {
                if (arr[i] < target)
                    k -= (target - arr[i]);
            }
        }

        return k >= 0;
    }

    int maximizeMedian(vector<int> &arr, int k)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int iniMedian = arr[n / 2];
        if (n % 2 == 0)
        {
            iniMedian += arr[n / 2 - 1];
            iniMedian /= 2;
        }

        int low = iniMedian, high = iniMedian + k;
        int bestMedian = iniMedian;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (isPossible(arr, mid, k))
            {
                bestMedian = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return bestMedian;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 3, 4, 5};
    int k = 3;
    int result = sol.maximizeMedian(arr, k);
    cout << "Maximized Median: " << result << endl;

    arr = {1, 3, 6, 4, 2};
    k = 10;
    result = sol.maximizeMedian(arr, k);
    cout << "Maximized Median: " << result << endl;
    return 0;
}