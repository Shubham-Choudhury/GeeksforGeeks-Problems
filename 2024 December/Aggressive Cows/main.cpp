// Link: https://www.geeksforgeeks.org/problems/aggressive-cows/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool canWePlace(vector<int> &stalls, int k, int minDist)
    {
        int cowsCnt = 1, last = stalls[0];
        for (int i = 1; i < stalls.size(); i++)
        {
            if (stalls[i] - last >= minDist)
            {
                cowsCnt++;
                last = stalls[i];
            }
            if (cowsCnt >= k)
                return true;
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k)
    {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int ans = 0;
        int i = 1, j = *max_element(begin(stalls), end(stalls)) - *min_element(begin(stalls), end(stalls));
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (canWePlace(stalls, k, mid))
            {
                ans = mid;
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution object;
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;
    cout << object.aggressiveCows(stalls, k) << endl;

    stalls = {10, 1, 2, 7, 5};
    k = 3;
    cout << object.aggressiveCows(stalls, k) << endl;

    stalls = {2, 12, 11, 3, 26, 7};
    k = 5;
    cout << object.aggressiveCows(stalls, k) << endl;
    return 0;
}