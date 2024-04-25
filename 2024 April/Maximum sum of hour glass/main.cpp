// Link: https://www.geeksforgeeks.org/problems/maximum-sum-of-hour-glass3842/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxSum(int n, int m, vector<vector<int>> &mat)
    {
        if (n < 3 || m < 3)
            return -1;
        int maxSum = INT_MIN;
        for (int i = 0; i <= n - 3; ++i)
        {
            for (int j = 0; j <= m - 3; ++j)
            {
                int sum = mat[i][j] + mat[i][j + 1] + mat[i][j + 2] +
                          mat[i + 1][j + 1] +
                          mat[i + 2][j] + mat[i + 2][j + 1] + mat[i + 2][j + 2];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum == INT_MIN ? -1 : maxSum;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> mat = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};
    int n = sizeof(mat) / sizeof(mat[0]);
    int m = sizeof(mat[0]) / sizeof(mat[0][0]);
    cout << obj.findMaxSum(n, m, mat) << endl;

    mat = mat = {{1, 2, 3},
                 {4, 5, 6}};
    n = sizeof(mat) / sizeof(mat[0]);
    m = sizeof(mat[0]) / sizeof(mat[0][0]);
    cout << obj.findMaxSum(n, m, mat) << endl;
    return 0;
}