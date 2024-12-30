// Link: https://www.geeksforgeeks.org/problems/word-break1352/1

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1102];
    int solve(int index, string &s, unordered_set<string> &st)
    {
        if (index >= s.size())
            return 1;
        if (dp[index] != -1)
            return dp[index];

        string temp = "";
        for (int i = index; i < s.size(); i++)
        {
            temp += s[i];
            if (st.find(temp) != st.end())
            {
                if (solve(i + 1, s, st))
                    return dp[index] = 1;
            }
        }
        return dp[index] = 0;
    }

    int wordBreak(string A, vector<string> &B)
    {

        memset(dp, -1, sizeof(dp));
        unordered_set<string> st(B.begin(), B.end());
        return solve(0, A, st);
    }
};

int main()
{
    Solution obj;
    string A = "ilikesamsung";
    vector<string> B = {"i", "like", "sam", "sung", "samsung", "mobile"};
    cout << obj.wordBreak(A, B) << endl;

    A = "ilike";
    cout << obj.wordBreak(A, B) << endl;

    return 0;
}