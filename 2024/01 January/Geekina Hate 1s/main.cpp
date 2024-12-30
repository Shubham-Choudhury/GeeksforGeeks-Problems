// Link: https://www.geeksforgeeks.org/problems/geekina-hate-1s/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long findNthNumber(int n, int k)
    {
        long long low = 0, high = 1e18;
        dp.resize(2, vector<vector<long long>>(65, vector<long long>(65)));

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long count = find(mid, k);
            if (count >= n)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
    vector<vector<vector<long long>>> dp;

    long long find(long long n, int k)
    {
        string s = bitset<64>(n).to_string();
        reset();
        return dpf(s, s.length(), 1, k);
    }

    long long dpf(string &s, int n, int tight, int k)
    {
        if (k < 0)
            return 0;
        if (n == 0)
        {
            return 1;
        }
        if (dp[tight][k][n] != -1)
            return dp[tight][k][n];
        int ub = (tight == 1 ? s[s.length() - n] - '0' : 1);
        long long ans = 0;
        for (int dig = 0; dig <= ub; dig++)
        {
            if (dig == ub)
                ans += dpf(s, n - 1, tight, k - dig);
            else
                ans += dpf(s, n - 1, 0, k - dig);
        }
        return dp[tight][k][n] = ans;
    }

    void reset()
    {
        for (int i = 0; i < 65; i++)
        {
            for (int j = 0; j < 65; j++)
            {
                dp[0][i][j] = -1;
                dp[1][i][j] = -1;
            }
        }
    }
};

int main()
{
    Solution obj;
    int N = 5;
    int K = 1;
    cout << obj.findNthNumber(N, K) << endl;
    N = 6;
    K = 2;
    cout << obj.findNthNumber(N, K);
    return 0;
}