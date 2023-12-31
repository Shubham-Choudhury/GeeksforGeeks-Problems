// Link: https://www.geeksforgeeks.org/problems/determinant-of-a-matrix-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int determinantOfMatrix(vector<vector<int>> matrix, int n)
    {
        if (n == 1)
            return matrix[0][0];
        if (n == 2)
        {
            return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            vector<vector<int>> temp;
            for (int j = 1; j < n; j++)
            {
                vector<int> v;
                for (int k = 0; k < n; k++)
                {
                    if (k == i)
                        continue;
                    else
                    {
                        v.push_back(matrix[j][k]);
                    }
                }
                temp.push_back(v);
            }

            if (i & 1)
                ans -= matrix[0][i] * determinantOfMatrix(temp, n - 1);
            else
                ans += matrix[0][i] * determinantOfMatrix(temp, n - 1);
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int n = 4;
    vector<vector<int>> matrix = {{1, 0, 2, -1}, {3, 0, 0, 5}, {2, 1, 4, -3}, {1, 0, 5, 0}};
    cout << obj.determinantOfMatrix(matrix, n) << endl;
    return 0;
}