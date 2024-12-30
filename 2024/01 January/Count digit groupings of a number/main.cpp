// Link: https://www.geeksforgeeks.org/problems/count-digit-groupings-of-a-number1520/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string &str, int i, int j, int needed, vector<vector<int>> &dp)
    {
        if (i > j)
        {
            return 1;
        }
        if (i == j)
        {
            return ((str[i] - '0') >= needed) ? 1 : 0;
        }
        if (dp[i][needed] != -1)
        {
            return dp[i][needed];
        }
        string s = "";
        int sum = 0;
        int ans = 0;
        for (int k = i; k <= j; k++)
        {
            s.push_back(str[k]);
            sum += (str[k] - '0');
            if (sum >= needed)
            {
                ans += solve(str, k + 1, j, sum, dp);
            }
        }
        return dp[i][needed] = ans;
    }
    
    int TotalCount(string str)
    {
        int needed = 0;
        int sum = 0;
        for (int i = 0; i < str.size(); i++)
        {
            sum += (str[i] - '0');
        }
        vector<vector<int>> dp(str.size(), vector<int>(sum + 1, -1));
        return solve(str, 0, str.size() - 1, needed, dp);
    }
};

int main()
{
    Solution obj;
    string str = "1119";
    cout << obj.TotalCount(str) << endl;
    str = "12";
    cout << obj.TotalCount(str) << endl;
    return 0;
}