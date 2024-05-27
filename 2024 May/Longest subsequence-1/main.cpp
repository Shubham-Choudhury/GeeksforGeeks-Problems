// Link: https://www.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestSubseq(int n, vector<int> &a)
    {
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (abs(a[i] - a[j]) == 1)
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {10, 9, 4, 5, 4, 8, 6};
    int n = arr.size();
    cout << obj.longestSubseq(n, arr) << endl;

    arr = {1, 2, 3, 4, 5};
    n = arr.size();
    cout << obj.longestSubseq(n, arr) << endl;

    return 0;
}
