// Link: https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool check(string S)
    {
        int s = 0, e = S.size() - 1;
        while (s < e)
        {
            if (S[s] != S[e])
            {
                return false;
            }
            s++;
            e--;
        }
        return true;
    }

    string longestPalindrome(string &s)
    {
        int n = s.size();
        int ans = 1;
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
        string ansstring = s.substr(0, 1);
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }
        for (int i = n - 1; i >= 1; i--)
        {
            if (s[i] == s[i - 1])
            {
                dp[i - 1][i] = true;
                ans = 2;
                ansstring = s.substr(i - 1, 2);
            }
        }
        for (int len = 3; len <= n; len++)
        {
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;

                if ((s[i] == s[j]) && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    if (len > ans)
                    {
                        ans = len;
                        ansstring = s.substr(i, j - i + 1);
                    }
                }
            }
        }

        return ansstring;
    }
};

int main()
{
    Solution obj;
    string s = "forgeeksskeegfor";
    cout << obj.longestPalindrome(s) << endl;

    s = "Geeks";
    cout << obj.longestPalindrome(s) << endl;

    s = "abc";
    cout << obj.longestPalindrome(s) << endl;
    return 0;
}