// Link: https://www.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int count(long long int n)
    {
        vector<long long int> dp(n + 1, 0);

        dp[0] = 1;
        for (int i = 3; i <= n; i++)
        {
            dp[i] += dp[i - 3];
        }
        for (int i = 5; i <= n; i++)
        {
            dp[i] += dp[i - 5];
        }
        for (int i = 10; i <= n; i++)
        {
            dp[i] += dp[i - 10];
        }

        return dp[n];
    }
};

int main()
{
    Solution obj;
    int n = 10;
    cout << obj.count(n) << endl;
    n = 20;
    cout << obj.count(n) << endl;
    return 0;
}