// Link: https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxGold(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();

        auto isValid = [&](int x, int y)
        { return x >= 0 && x < n && y >= 0 && y < m; };

        for (int y = m - 2; y >= 0; y--)
        {
            for (int x = 0; x < n; x++)
            {
                int maxprev = 0;

                if (isValid(x - 1, y + 1))
                {
                    maxprev = max(maxprev, mat[x - 1][y + 1]);
                }
                if (isValid(x, y + 1))
                {
                    maxprev = max(maxprev, mat[x][y + 1]);
                }
                if (isValid(x + 1, y + 1))
                {
                    maxprev = max(maxprev, mat[x + 1][y + 1]);
                }

                mat[x][y] += maxprev;
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result = max(result, mat[i][0]);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat = {{1, 3, 3}, {2, 1, 4}, {0, 6, 4}};
    int result = sol.maxGold(mat);
    cout << "Maximum amount of gold " << result << endl;

    mat = {{1, 3, 1, 5}, {2, 2, 4, 1}, {5, 0, 2, 3}, {0, 6, 1, 2}};
    result = sol.maxGold(mat);
    cout << "Maximum amount of gold " << result << endl;

    mat = {{1, 3, 3}, {2, 1, 4}, {0, 7, 5}};
    result = sol.maxGold(mat);
    cout << "Maximum amount of gold " << result << endl;

    return 0;
}