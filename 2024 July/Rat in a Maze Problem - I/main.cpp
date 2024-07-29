// Link: https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

class Solution
{
public:
    vector<string> findPath(vector<vector<int>> &mat)
    {
        int n = mat.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<string> paths;

        function<void(int, int, string)> helper = [&](int row, int col, string path)
        {
            if (mat[row][col] == 0)
            {
                return;
            }
            if (row == n - 1 && col == n - 1)
            {
                paths.push_back(path);
            }

            visited[row][col] = 1;
            if (row + 1 < n && !visited[row + 1][col])
            {
                helper(row + 1, col, path + "D");
            }
            if (row - 1 >= 0 && !visited[row - 1][col])
            {
                helper(row - 1, col, path + "U");
            }
            if (col + 1 < n && !visited[row][col + 1])
            {
                helper(row, col + 1, path + "R");
            }
            if (col - 1 >= 0 && !visited[row][col - 1])
            {
                helper(row, col - 1, path + "L");
            }
            visited[row][col] = 0;
        };

        helper(0, 0, "");
        if (!paths.empty())
        {
            return paths;
        }
        else
        {
            return {"-1"};
        }
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> mat1 = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans1 = obj.findPath(mat1);
    for (const auto &path : ans1)
    {
        cout << path << " ";
    }
    cout << endl;

    vector<vector<int>> mat2 = {{1, 0}, {1, 0}};
    vector<string> ans2 = obj.findPath(mat2);
    for (const auto &path : ans2)
    {
        cout << path << " ";
    }
    cout << endl;

    return 0;
}
