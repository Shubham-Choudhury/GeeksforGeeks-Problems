// Link: https://www.geeksforgeeks.org/problems/rotten-oranges2536/1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int, int>, int>> pq;
        bool vis[n][m];
        int fresh_cnt = 0;
        int max_t = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 2)
                {
                    pq.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else
                {
                    vis[i][j] = 0;
                }
                if (mat[i][j] == 1)
                    fresh_cnt++;
            }
        }
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        int cnt = 0;
        while (!pq.empty())
        {
            int r = pq.front().first.first;
            int c = pq.front().first.second;
            int t = pq.front().second;
            max_t = max(max_t, t);
            pq.pop();
            for (int i = 0; i < 4; i++)
            {
                int nRow = r + delRow[i];
                int nCol = c + delCol[i];
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && mat[nRow][nCol] == 1 && vis[nRow][nCol] == 0)
                {
                    pq.push({{nRow, nCol}, t + 1});
                    vis[nRow][nCol] = 2;
                    cnt++;
                }
            }
        }
        if (cnt != fresh_cnt)
            return -1;
        else
            return max_t;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> mat = {{0, 1, 2},
                               {0, 1, 2},
                               {2, 1, 1}};
    int result = obj.orangesRotting(mat);
    cout << result << endl;

    mat = {{2, 2, 0, 1}};
    result = obj.orangesRotting(mat);
    cout << result << endl;

    mat = {{2, 2, 2},
           {0, 2, 0}};
    result = obj.orangesRotting(mat);
    cout << result << endl;

    return 0;
}