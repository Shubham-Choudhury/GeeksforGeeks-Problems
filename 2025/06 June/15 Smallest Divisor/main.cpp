// Link: https://www.geeksforgeeks.org/problems/smallest-divisor/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int smallestDivisor(vector<int> &arr, int k)
    {
        int low = 1, high = *max_element(arr.begin(), arr.end());
        int res = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int sum = 0;

            for (int ele : arr)
            {
                sum += (ele + mid - 1) / mid;
            }

            if (sum <= k)
            {
                res = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 5, 9};
    int k = 6;
    cout << "Smallest Divisor: " << sol.smallestDivisor(arr, k) << endl;

    arr = {1, 1, 1, 1};
    k = 4;
    cout << "Smallest Divisor: " << sol.smallestDivisor(arr, k) << endl;
    return 0;
}