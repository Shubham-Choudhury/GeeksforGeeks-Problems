// Link: https://www.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void palindromes(const string &s, vector<vector<bool>> &dp)
    {
        int n = s.size();

        for (int i = 0; i < n; ++i)
            dp[i][i] = true;

        for (int i = 0; i < n - 1; ++i)
            dp[i][i + 1] = (s[i] == s[i + 1]);

        for (int len = 3; len <= n; ++len)
        {
            for (int i = 0; i <= n - len; ++i)
            {
                int j = i + len - 1;
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }
    }

    void backtrack(int idx, const string &s, vector<string> &curr,
                   vector<vector<string>> &res, vector<vector<bool>> &dp)
    {

        if (idx == s.size())
        {
            res.push_back(curr);
            return;
        }

        for (int i = idx; i < s.size(); ++i)
        {
            if (dp[idx][i])
            {
                curr.push_back(s.substr(idx, i - idx + 1));
                backtrack(i + 1, s, curr, res, dp);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> palinParts(string &s)
    {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(s.size() + 1, false));
        palindromes(s, dp);
        vector<vector<string>> res;
        vector<string> curr;
        backtrack(0, s, curr, res, dp);
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "geeks";
    vector<vector<string>> result = sol.palinParts(s);
    for (const auto &part : result)
    {
        for (const auto &str : part)
        {
            cout << str << " ";
        }
        cout << endl;
    }
    cout << "Total partitions: " << result.size() << endl;

    s = "abcba";
    result = sol.palinParts(s);
    for (const auto &part : result)
    {
        for (const auto &str : part)
        {
            cout << str << " ";
        }
        cout << endl;
    }
    cout << "Total partitions: " << result.size() << endl;
    return 0;
}