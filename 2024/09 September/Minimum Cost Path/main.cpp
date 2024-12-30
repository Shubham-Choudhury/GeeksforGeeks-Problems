// Link: https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    int minimumCostPath(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 1e9));
        vis[0][0] = grid[0][0];
        set<pair<int, pair<int, int>>> s;
        s.insert({grid[0][0], {0, 0}});
        int r[4] = {-1, 1, 0, 0};
        int c[4] = {0, 0, 1, -1};
        while (!s.empty())
        {
            auto it = s.begin();
            s.erase(it);
            int wt = it->first;
            int row = it->second.first;
            int col = it->second.second;
            for (int k = 0; k < 4; k++)
            {
                int nr = row + r[k];
                int nc = col + c[k];
                if (nr >= 0 and nc >= 0 and nr < n and nc < m)
                {
                    if (wt + grid[nr][nc] < vis[nr][nc])
                    {
                        vis[nr][nc] = wt + grid[nr][nc];
                        s.insert({wt + grid[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        return vis[n - 1][m - 1];
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> grid = {{9, 4, 9, 9}, {6, 7, 6, 4}, {8, 3, 3, 7}, {7, 4, 9, 10}};
    cout << obj.minimumCostPath(grid) << endl;

    grid = {{4, 4}, {3, 7}};
    cout << obj.minimumCostPath(grid) << endl;
    return 0;
}