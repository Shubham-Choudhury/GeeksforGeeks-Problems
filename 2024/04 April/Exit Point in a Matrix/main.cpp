// Link: https://www.geeksforgeeks.org/problems/exit-point-in-a-matrix0905/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>> &matrix)
    {

        int pos = 0, i = 0, j = 0, pi = -1, pj = -1;
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        while (0 <= i and i < n and 0 <= j and j < m)
        {
            if (matrix[i][j])
                matrix[i][j] = 0, pos = (pos + 1) % 4;
            pi = i, pj = j, i += dx[pos], j += dy[pos];
        }
        return {pi, pj};
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> matrix = {{0, 1, 0},
                                  {0, 1, 1},
                                  {0, 0, 0}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> ans = obj.FindExitPoint(n, m, matrix);
    cout << ans[0] << " " << ans[1] << endl;

    matrix = {{0, 0}};
    n = matrix.size();
    m = matrix[0].size();
    ans = obj.FindExitPoint(n, m, matrix);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}