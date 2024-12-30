// Link: https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;

        if (m == 0)
        {
            return result;
        }

        vector<vector<bool>> seen(m, vector<bool>(n, false));

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        int r = 0, c = 0;
        int di = 0;

        for (int i = 0; i < m * n; i++)
        {
            result.push_back(matrix[r][c]);
            seen[r][c] = true;
            int newR = r + dr[di], newC = c + dc[di];

            if (0 <= newR && newR < m && 0 <= newC && newC < n && !seen[newR][newC])
            {
                r = newR;
                c = newC;
            }
            else
            {
                di = (di + 1) % 4;
                r += dr[di];
                c += dc[di];
            }
        }
        return result;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<int> result = obj.spirallyTraverse(matrix);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    result = obj.spirallyTraverse(matrix);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
