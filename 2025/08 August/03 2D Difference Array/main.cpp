// Link: https://www.geeksforgeeks.org/problems/2-d-difference-array/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> applyDiff2D(vector<vector<int>> &mat,
                                    vector<vector<int>> &opr)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> diff(n, vector<int>(m, 0));

        for (auto &q : opr)
        {
            int v = q[0];
            int r1 = q[1], c1 = q[2], r2 = q[3], c2 = q[4];

            diff[r1][c1] += v;

            if (c2 + 1 < m)
                diff[r1][c2 + 1] -= v;

            if (r2 + 1 < n)
                diff[r2 + 1][c1] -= v;

            if (r2 + 1 < n && c2 + 1 < m)
                diff[r2 + 1][c2 + 1] += v;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                diff[i][j] += diff[i][j - 1];
            }
        }

        for (int j = 0; j < m; j++)
        {
            for (int i = 1; i < n; i++)
            {
                diff[i][j] += diff[i - 1][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mat[i][j] += diff[i][j];
            }
        }

        return mat;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat = {{1, 2, 3}, {1, 1, 0}, {4, -2, 2}};
    vector<vector<int>> opr = {{2, 0, 0, 1, 1}, {-1, 1, 0, 2, 2}};
    vector<vector<int>> result = sol.applyDiff2D(mat, opr);
    for (const auto &row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}