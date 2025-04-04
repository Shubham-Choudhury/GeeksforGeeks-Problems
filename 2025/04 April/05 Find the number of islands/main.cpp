// Link: https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = true;

        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int d = 0; d < 8; d++)
        {
            int ni = i + dx[d];
            int nj = j + dy[d];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                grid[ni][nj] == 'L' && !visited[ni][nj])
            {
                dfs(ni, nj, grid, visited);
            }
        }
    }

    int countIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'L' && !visited[i][j])
                {
                    dfs(i, j, grid, visited);
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
    vector<vector<char>> grid = {
        {'L', 'L', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'W', 'W'},
        {'L', 'W', 'L', 'L', 'W'},
    };
    cout << obj.countIslands(grid) << endl;

    grid = {
        {'W', 'L', 'L', 'L', 'W', 'W', 'W'},
        {'W', 'W', 'L', 'L', 'W', 'L', 'W'},
    };
    cout << obj.countIslands(grid) << endl;
    return 0;
}