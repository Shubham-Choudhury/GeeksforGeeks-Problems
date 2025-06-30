// Link: https://www.geeksforgeeks.org/problems/lcs-of-three-strings0028/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int LCSof3(string A, string B, string C, int n1, int n2, int n3)
    {
        int dp[n1 + 1][n2 + 1][n3 + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                for (int k = 1; k <= n3; k++)
                {
                    if (A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1])
                    {
                        dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                    }
                    else
                    {
                        dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
                    }
                }
            }
        }
        return dp[n1][n2][n3];
    }
};

int main()
{
    Solution obj;
    string A = "geeks";
    string B = "geeksfor";
    string C = "geeksforgeeks";
    int n1 = A.length();
    int n2 = B.length();
    int n3 = C.length();
    cout << obj.LCSof3(A, B, C, n1, n2, n3) << endl;

    A = "abcd";
    B = "efgh";
    C = "ijkl";
    n1 = A.length();
    n2 = B.length();
    n3 = C.length();
    cout << obj.LCSof3(A, B, C, n1, n2, n3) << endl;
    return 0;
}