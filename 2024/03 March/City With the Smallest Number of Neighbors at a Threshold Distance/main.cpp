// Link: https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
    {

        vector<vector<int>> mat(n, vector<int>(n, 1e9));
        for (auto it : edges)
        {
            mat[it[0]][it[1]] = it[2];
            mat[it[1]][it[0]] = it[2];
        }
        for (int i = 0; i < n; i++)
        {
            mat[i][i] = 0;
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
        int ans;
        int mini = 1e9;
        for (int i = 0; i < n; i++)
        {
            int reach = 0;
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] <= distanceThreshold)
                {
                    reach++;
                }
            }
            if (reach <= mini)
            {
                mini = reach;
                ans = i;
            }
        }

        return ans;
    }
};
int main()
{
    Solution obj;
    vector<vector<int>> edges = {{0, 1, 3},
                                 {1, 2, 1},
                                 {1, 3, 4},
                                 {2, 3, 1}};
    int n = 4, m = 4, distanceThreshold = 4;
    cout << obj.findCity(n, m, edges, distanceThreshold);
    edges = {{0, 1, 2},
             {0, 4, 8},
             {1, 2, 3},
             {1, 4, 2},
             {2, 3, 1},
             {3, 4, 1}};
    n = 5, m = 6, distanceThreshold = 2;
    cout << obj.findCity(n, m, edges, distanceThreshold);
    return 0;
}