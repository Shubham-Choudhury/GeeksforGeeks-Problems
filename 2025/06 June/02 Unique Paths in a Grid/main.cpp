// Link: https://www.geeksforgeeks.org/problems/unique-paths-in-a-grid--170647/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePaths(vector<vector<int>> &grid)
    {
        int r = grid.size(), c = grid[0].size();
        vector<int> dp(c, 0);

        dp[0] = (grid[0][0] == 0) ? 1 : 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 1)
                {
                    dp[j] = 0;
                }
                else if (j > 0)
                {
                    dp[j] = (dp[j] + dp[j - 1]);
                }
            }
        }

        return dp[c - 1];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}};
    cout << "Unique Paths: " << sol.uniquePaths(grid) << endl;

    grid = {{1, 0, 1}};
    cout << "Unique Paths: " << sol.uniquePaths(grid) << endl;
    return 0;
}