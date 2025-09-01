// Link: https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();

        int i = 0, j = n - 1;
        while (i < j)
        {
            if (mat[j][i] == 1)
                j--;

            else
                i++;
        }

        int c = i;

        for (i = 0; i < n; i++)
        {
            if (i == c)
                continue;

            if (mat[c][i] || !mat[i][c])
                return -1;
        }

        return c;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat = {
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0}};
    int result = sol.celebrity(mat);
    cout << "Celebrity index: " << result << endl;

    mat = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}};
    result = sol.celebrity(mat);
    cout << "Celebrity index: " << result << endl;

    mat = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}};
    result = sol.celebrity(mat);
    cout << "Celebrity index: " << result << endl;

    return 0;
}