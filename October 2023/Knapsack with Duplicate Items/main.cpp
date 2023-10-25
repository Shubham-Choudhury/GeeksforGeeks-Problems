
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1001][1001];
    int f(int W, int wt[], int val[], int n)
    {
        if (W <= 0 || n == 0)
            return 0;
        if (dp[W][n] != -1)
            return dp[W][n];
        if (wt[n - 1] <= W)
            return dp[W][n] = max(f(W, wt, val, n - 1), (f(W - wt[n - 1], wt, val, n) + val[n - 1]));
        else
            return dp[W][n] = f(W, wt, val, n - 1);
    }
    
    int knapSack(int n, int W, int val[], int wt[])
    {
        memset(dp, -1, sizeof(dp));
        return f(W, wt, val, n);
    }
};

int main()
{
    int n, W;
    n = 2;
    W = 3;
    int val[n] = {1, 1};
    int wt[n] = {2, 1};
    Solution ob;
    cout << ob.knapSack(n, W, val, wt) << endl;
    return 0;
}