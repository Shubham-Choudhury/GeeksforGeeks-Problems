// Link: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-matrix-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return list of integers that form the boundary
    // traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int>> mat, int n, int m)
    {
        vector<int> ans;
        for (int i = 0; i < m; i++)
            ans.push_back(mat[0][i]);
        for (int i = 1; i < n; i++)
            ans.push_back(mat[i][m - 1]);
        if (n != 1)
            for (int i = m - 2; i >= 0; i--)
                ans.push_back(mat[n - 1][i]);
        if (m != 1)
            for (int i = n - 2; i > 0; i--)
                ans.push_back(mat[i][0]);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n);

        for (int i = 0; i < n; i++)
        {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}