// Link: https://www.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{

    bool isPossible(vector<vector<int>> &grid, int curr_row, int curr_col, int val)
    {
        int N = grid.size();
        for (int i = 0; i < N; i++)
        {
            if (grid[curr_row][i] == val)
                return false;
            if (grid[i][curr_col] == val)
                return false;
        }

        for (int i = 0; i < N; i++)
        {
            if (grid[3 * (curr_row / 3) + i / 3][3 * (curr_col / 3) + i % 3] == val)
                return false;
        }

        return true;
    }

    bool helper(vector<vector<int>> &grid)
    {
        int N = grid.size();
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == 0)
                {
                    for (int index = 1; index <= 9; index++)
                    {
                        if (isPossible(grid, i, j, index))
                        {
                            grid[i][j] = index;
                            bool nextFunCall = helper(grid);
                            if (nextFunCall)
                            {
                                return true;
                            }
                            else
                            {
                                grid[i][j] = 0;
                            }
                        }
                    }
                    if (grid[i][j] == 0)
                        return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<int>> &mat)
    {
        helper(mat);
    }
};

int main()
{
    Solution object;
    vector<vector<int>> mat = {
        {3, 0, 6, 5, 7, 8, 4, 0, 0},
        {5, 6, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 0, 1, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 8, 6, 3, 0, 0}};

    object.solveSudoku(mat);

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat.size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    mat = {
        {3, 1, 6, 5, 7, 8, 4, 9, 2},
        {5, 2, 9, 1, 3, 4, 7, 6, 8},
        {4, 8, 7, 6, 2, 9, 5, 3, 1},
        {2, 6, 3, 0, 1, 5, 9, 8, 7},
        {9, 7, 4, 8, 6, 0, 1, 2, 5},
        {8, 5, 1, 7, 9, 2, 6, 4, 3},
        {1, 3, 8, 0, 4, 7, 2, 0, 6},
        {6, 9, 2, 3, 5, 1, 8, 7, 4},
        {7, 4, 5, 0, 8, 6, 3, 1, 0}};
    object.solveSudoku(mat);
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat.size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
