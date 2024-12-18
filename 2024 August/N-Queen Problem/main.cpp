// Link: https://www.geeksforgeeks.org/problems/n-queen-problem0315/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValid(int i, int j, vector<vector<int>> &matrix)
    {
        int x = i, y = j;
        int n = matrix.size();
        for (int j = 0; j < n; j++)
        {
            if (matrix[x][j] != 0)
                return false;
        }
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][y] != 0)
                return false;
        }
        for (int i = x, j = y; i < n && j < n; i++, j++)
        {
            if (matrix[i][j] != 0)
                return false;
        }
        for (int i = x, j = y; i >= 0 && j >= 0; i--, j--)
        {
            if (matrix[i][j] != 0)
                return false;
        }
        for (int i = x, j = y; i < n && j >= 0; i++, j--)
        {
            if (matrix[i][j] != 0)
                return false;
        }
        for (int i = x, j = y; i >= 0 && j < n; i--, j++)
        {
            if (matrix[i][j] != 0)
                return false;
        }
        return true;
    }

    void solve(int j, vector<vector<int>> &matrix, vector<int> &temp, vector<vector<int>> &ans)
    {
        int n = matrix.size();
        if (j == n)
        {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (isValid(i, j, matrix))
            {
                temp.push_back(i + 1);
                matrix[i][j] = i + 1;
                solve(j + 1, matrix, temp, ans);
                matrix[i][j] = 0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> nQueen(int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        solve(0, matrix, temp, ans);
        return ans;
    }
};

int main()
{
    Solution obj;
    int n = 1;
    vector<vector<int>> ans = obj.nQueen(n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    n = 4;
    ans = obj.nQueen(n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}