// Link: https://www.geeksforgeeks.org/problems/toeplitz-matrix/1

#include <iostream>
#include <vector>
using namespace std;

bool isToepliz(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    int c = mat[0][0];
    for (int i = 0, j = 0; i < n && j < m; i++, j++)
    {
        if (mat[i][j] != c)
            return false;
    }
    return true;
}

int main()
{
    vector<vector<int>> mat = {{6, 7, 8}, {4, 6, 7}, {1, 4, 6}};
    cout << isToepliz(mat) << endl;

    mat = {{1, 2, 3}, {4, 5, 6}};
    cout << isToepliz(mat) << endl;

    return 0;
}