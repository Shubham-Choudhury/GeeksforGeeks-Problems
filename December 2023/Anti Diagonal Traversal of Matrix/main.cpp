// Link: https://www.geeksforgeeks.org/problems/print-diagonally1623/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix)
    {
        // Code here
        int n = matrix.size();
        vector<int> ans;
        if (n == 1)
            return {matrix[0][0]};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                ans.push_back(matrix[j][i - j]);
            }
        }
        for (int i = 1; i < n; i++)
        {
            int k = i;
            for (int j = n - 1; j >= i; j--)
            {
                ans.push_back(matrix[k++][j]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> matrix = {{1, 2}, {3, 4}};
    vector<int> ans = obj.antiDiagonalPattern(matrix);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}