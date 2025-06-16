// Link: https://www.geeksforgeeks.org/problems/coin-piles5152/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int minimumCoins(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        vector<int> prefix(n, 0);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + arr[i];

        int ans = INT_MAX, prev = 0;

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && arr[i] == arr[i - 1])
                continue;

            if (i > 0)
            {
                prev = prefix[i - 1];
            }
            int pos = upper_bound(arr.begin() + i, arr.end(), arr[i] + k) - arr.begin();
            int totalToRemove =
                prev + prefix[n - 1] - prefix[pos - 1] - (n - pos) * (arr[i] + k);
            ans = min(ans, totalToRemove);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, 2, 2, 2};
    int k = 0;
    cout << sol.minimumCoins(arr, k) << endl;

    arr = {1, 5, 1, 2, 5, 1};
    k = 3;
    cout << sol.minimumCoins(arr, k) << endl;

    return 0;
}