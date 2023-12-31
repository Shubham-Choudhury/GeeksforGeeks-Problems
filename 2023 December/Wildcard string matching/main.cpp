// Link: https://www.geeksforgeeks.org/problems/wildcard-string-matching1126/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string &wild, string &pattern, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0 && j < 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (wild[i] == pattern[j])
            return dp[i][j] = solve(wild, pattern, i - 1, j - 1, dp);
        if (wild[i] == '?')
            return dp[i][j] = solve(wild, pattern, i - 1, j - 1, dp);
        if (wild[i] == '*')
            return dp[i][j] = (solve(wild, pattern, i - 1, j - 1, dp) || solve(wild, pattern, i, j - 1, dp) || solve(wild, pattern, i - 1, j, dp));
        return dp[i][j] = 0;
    }

    bool match(string wild, string pattern)
    {
        vector<vector<int>> dp(wild.size(), vector<int>(pattern.size(), -1));
        return solve(wild, pattern, wild.size() - 1, pattern.size() - 1, dp);
    }
};

int main()
{
    Solution obj;
    string wild = "ge*ks";
    string pattern = "geeks";
    cout << obj.match(wild, pattern) << endl;

    wild = "ge?ks*";
    pattern = "geeksforgeeks";
    cout << obj.match(wild, pattern) << endl;
    return 0;
}