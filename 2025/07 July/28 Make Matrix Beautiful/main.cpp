// Link: https://www.geeksforgeeks.org/problems/make-matrix-beautiful-1587115620/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int balanceSums(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int res = 0;
        int maxSum = 0;

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
                sum += mat[i][j];
            maxSum = max(sum, maxSum);
        }

        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
                sum += mat[i][j];
            maxSum = max(sum, maxSum);
        }

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += mat[i][j];
            }
            res += (maxSum - sum);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat = {
        {1, 2},
        {3, 4}};
    int result = sol.balanceSums(mat);
    cout << "Minimum operations to make the matrix beautiful: " << result << endl;

    mat = {
        {1, 2, 3},
        {4, 2, 3},
        {3, 2, 1}};
    result = sol.balanceSums(mat);
    cout << "Minimum operations to make the matrix beautiful: " << result << endl;
    return 0;
}