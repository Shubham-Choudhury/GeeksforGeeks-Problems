// Link: https://www.geeksforgeeks.org/problems/sum-of-upper-and-lower-triangles-1587115621/1

#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>

class Solution
{
public:
    vector<int> sumTriangles(vector<vector<int>> &matrix, int n)
    {
        int upper = 0, lower = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i <= j)
                {
                    upper += matrix[i][j];
                }
                if (i >= j)
                {
                    lower += matrix[i][j];
                }
            }
        }
        return {upper, lower};
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> matrix = {{6, 5, 4}, {1, 2, 5}, {7, 9, 7}};
    int n = 3;
    vector<int> result = obj.sumTriangles(matrix, n);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}
