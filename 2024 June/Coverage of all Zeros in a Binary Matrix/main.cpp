// Link: https://www.geeksforgeeks.org/problems/coverage-of-all-zeros-in-a-binary-matrix4024/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int FindCoverage(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 1)
                {
                    continue;
                }

                if (i + 1 < n)
                {
                    ans += matrix[i + 1][j];
                }

                if (j + 1 < m)
                {
                    ans += matrix[i][j + 1];
                }

                if (i >= 1)
                {
                    ans += matrix[i - 1][j];
                }

                if (j >= 1)
                {
                    ans += matrix[i][j - 1];
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> matrix = {{0, 1, 0}, {0, 1, 1}, {0, 0, 0}};
    cout << obj.FindCoverage(matrix) << endl;

    matrix = {{0, 1}};
    cout << obj.FindCoverage(matrix) << endl;

    return 0;
}