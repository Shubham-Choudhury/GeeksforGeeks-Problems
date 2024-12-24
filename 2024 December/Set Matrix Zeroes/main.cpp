// Link: https://www.geeksforgeeks.org/problems/set-matrix-zeroes/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void setMatrixZeroes(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int col0 = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    mat[i][0] = 0;
                    if (j != 0)
                        mat[0][j] = 0;

                    else
                        col0 = 0;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (mat[i][j] != 0)
                {
                    if (mat[i][0] == 0 || mat[0][j] == 0)
                    {
                        mat[i][j] = 0;
                    }
                }
            }
        }
        if (mat[0][0] == 0)
        {
            for (int j = 0; j < m; j++)
            {
                mat[0][j] = 0;
            }
        }
        if (col0 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                mat[i][0] = 0;
            }
        }
    }
};

int main()
{
    Solution object;
    vector<vector<int>> mat = {{1, -1, 1},
                               {-1, 0, 1},
                               {1, -1, 1}};
    object.setMatrixZeroes(mat);
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    mat = {{0, 1, 2, 0},
           {3, 4, 5, 2},
           {1, 3, 1, 5}};
    object.setMatrixZeroes(mat);
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}