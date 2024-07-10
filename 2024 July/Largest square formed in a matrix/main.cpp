// Link: https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int maxSide = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (mat[i][j] == 1)
                {
                    if (i == 0 || j == 0)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }

        return maxSide;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> mat = {{0, 1, 1, 0, 1},
                               {1, 1, 0, 1, 0},
                               {0, 1, 1, 1, 0},
                               {1, 1, 1, 1, 0},
                               {1, 1, 1, 1, 1},
                               {0, 0, 0, 0, 0}};
    int n = mat.size();
    int m = mat[0].size();
    cout << obj.maxSquare(n, m, mat) << endl;

    mat = {{1, 1},
           {1, 1}};
    n = mat.size();
    m = mat[0].size();
    cout << obj.maxSquare(n, m, mat) << endl;

    mat = {{0, 0},
           {0, 0}};
    n = mat.size();
    m = mat[0].size();
    cout << obj.maxSquare(n, m, mat) << endl;

    return 0;
}