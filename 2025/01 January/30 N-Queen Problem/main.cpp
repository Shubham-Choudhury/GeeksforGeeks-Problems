// Link: https://www.geeksforgeeks.org/problems/n-queen-problem0315/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    bool check(int i, int j, int n, vector<vector<int>> &grid)
    {
        for (int col = 0; col < j; col++)
        {
            if (grid[i][col] == 1)
                return 0;
        }
        for (int row = 0; row < i; row++)
        {
            if (grid[row][j] == 1)
                return 0;
        }

        int a = i, b = j;
        while (a > -1 && b > -1)
        {
            a--;
            b--;
            if (a > -1 && b > -1)
                if (grid[a][b] == 1)
                    return 0;
        }

        a = i, b = j;
        while (a > -1 && a < n && b > -1 && b < n)
        {
            a++;
            b--;
            if (a > -1 && a < n && b > -1 && b < n)
                if (grid[a][b] == 1)
                    return 0;
        }

        return 1;
    }

    void backtrack(int col, vector<vector<int>> &grid, vector<int> &path, int n)
    {
        if (path.size() == n)
        {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (check(i, col, n, grid))
            {
                grid[i][col] = 1;
                path.push_back(i + 1);
                backtrack(col + 1, grid, path, n);
                grid[i][col] = 0;
                path.pop_back();
            }
        }
        return;
    }

    vector<vector<int>> nQueen(int n)
    {
        if (n == 1)
            return {{1}};

        vector<vector<int>> grid(n, vector<int>(n, 0));
        vector<int> path;
        backtrack(0, grid, path, n);
        if (ans.size() == 0)
            return {};
        return ans;
    }
};

int main()
{
    Solution solution;
    int n = 1;
    vector<vector<int>> ans = solution.nQueen(n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    n = 4;
    ans = solution.nQueen(n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    n = 2;
    ans = solution.nQueen(n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}