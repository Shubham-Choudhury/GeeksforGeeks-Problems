// Link: https://www.geeksforgeeks.org/problems/set-matrix-zeroes/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void setMatrixZeroes(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();

        int c0 = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    mat[i][0] = 0;
                    if (j == 0)
                        c0 = 0;
                    else
                        mat[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (mat[i][0] == 0 || mat[0][j] == 0)
                {
                    mat[i][j] = 0;
                }
            }
        }

        if (mat[0][0] == 0)
        {
            for (int j = 0; j < m; j++)
                mat[0][j] = 0;
        }

        if (c0 == 0)
        {
            for (int i = 0; i < n; i++)
                mat[i][0] = 0;
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat = {
        {1, -1, 1},
        {-1, 0, 1},
        {1, -1, 1}};
    sol.setMatrixZeroes(mat);
    cout << "Matrix after setting zeroes:" << endl;
    for (const auto &row : mat)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "Done!" << endl;

    mat = {
        {0, 1, 2, 0},
        {1, 2, 6, 2},
        {1, 3, 1, 8}};
    sol.setMatrixZeroes(mat);
    cout << "Matrix after setting zeroes:" << endl;
    for (const auto &row : mat)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "Done!" << endl;

    return 0;
}