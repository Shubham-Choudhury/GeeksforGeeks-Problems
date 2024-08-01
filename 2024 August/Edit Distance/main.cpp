// Link: https://www.geeksforgeeks.org/problems/edit-distance3702/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int editDistance(string str1, string str2)
    {
        vector<vector<int>> dp(str1.length() + 1, vector<int>(str2.length() + 1, 0));
        for (int j = 0; j <= str2.length(); j++)
        {
            dp[str1.length()][j] = str2.length() - j;
        }

        for (int i = 0; i <= str1.length(); i++)
        {
            dp[i][str2.length()] = str1.length() - i;
        }

        for (int i = str1.length() - 1; i >= 0; i--)
        {
            for (int j = str2.length() - 1; j >= 0; j--)
            {
                int ans = 0;
                if (str1[i] == str2[j])
                {
                    ans = dp[i + 1][j + 1];
                }
                else
                {
                    int insert = 1 + dp[i][j + 1];
                    int del = 1 + dp[i + 1][j];
                    int rep = 1 + dp[i + 1][j + 1];
                    ans = min(insert, min(del, rep));
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }
};

int main()
{
    Solution obj;
    string str1 = "geek";
    string srt2 = "gesek";
    cout << obj.editDistance(str1, srt2) << endl;

    str1 = "gfg";
    srt2 = "gfg";
    cout << obj.editDistance(str1, srt2) << endl;
    return 0;
}