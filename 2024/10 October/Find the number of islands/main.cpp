// Link: https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        grid[x][y] = '0';

        for (int i = 0; i < 8; ++i)
        {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];
            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == '1')
            {
                dfs(grid, newX, newY);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;

        int count = 0;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};

int main()
{
    Solution obj;
    vector<vector<char>> grid = {{0, 1}, {1, 0}, {1, 1}, {1, 0}};
    cout << obj.numIslands(grid) << endl;

    grid = {{0, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 1, 0, 1, 0}};
    cout << obj.numIslands(grid) << endl;
    return 0;
}