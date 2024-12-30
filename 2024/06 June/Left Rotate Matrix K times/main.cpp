// Link: https://www.geeksforgeeks.org/problems/left-rotate-matrix-k-times2351/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat)
    {
        int n = mat[0].size(), m = mat.size();
        k = k % n;
        int temp[k];
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < k; i++)
            {
                temp[i] = mat[j][i];
            }
            for (int i = 0; i < n - k; i++)
            {
                mat[j][i] = mat[j][i + k];
            }
            for (int i = n - k; i < n; i++)
            {
                mat[j][i] = temp[i - n + k];
            }
        }
        return mat;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = 1;
    vector<vector<int>> ans = obj.rotateMatrix(k, mat);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    mat = {{3, 1, 2}, {6, 4, 5}, {9, 7, 8}};
    k = 2;
    ans = obj.rotateMatrix(k, mat);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}