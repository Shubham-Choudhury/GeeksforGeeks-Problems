// Link: https://www.geeksforgeeks.org/problems/edit-distance3702/1

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
    int solve(string s1, string s2, int idx1, int idx2, vector<vector<int>> &dp)
    {
        if (idx1 == s1.size())
        {
            if (idx2 == s2.size())
                return 0;
            return s2.size() - idx2;
        }
        if (idx2 == s2.size())
        {
            return s1.size() - idx1;
        }

        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        if (s1[idx1] == s2[idx2])
            return dp[idx1][idx2] = solve(s1, s2, idx1 + 1, idx2 + 1, dp);

        int insert = 1 + solve(s1, s2, idx1, idx2 + 1, dp);
        int deleteFn = 1 + solve(s1, s2, idx1 + 1, idx2, dp);
        int replace = 1 + solve(s1, s2, idx1 + 1, idx2 + 1, dp);

        return dp[idx1][idx2] = min(insert, min(deleteFn, replace));
    }

public:
    int editDistance(string &s1, string &s2)
    {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(s1, s2, 0, 0, dp);
    }
};

int main()
{
    Solution obj;
    string s1 = "geek", s2 = "gesek";
    cout << obj.editDistance(s1, s2) << endl;

    s1 = "gfg", s2 = "gfg";
    cout << obj.editDistance(s1, s2) << endl;

    s1 = "abcd", s2 = "bcfe";
    cout << obj.editDistance(s1, s2) << endl;
    return 0;
}
