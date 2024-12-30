// Link: https://www.geeksforgeeks.org/problems/count-pairs-sum-in-matrices4332/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
    {
        int count = 0;
        int j = n * n - 1;
        int i = 0;
        while (j >= 0 && i < n * n)
        {
            int row1 = i / n;
            int col1 = i % n;
            int row2 = j / n;
            int col2 = j % n;
            if (mat1[row1][col1] + mat2[row2][col2] == x)
            {
                count++;
                i++;
                j--;
            }
            else if (mat1[row1][col1] + mat2[row2][col2] > x)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return count;
    }
};

int main()
{
    Solution obj;
    int n = 3, x = 21;
    vector<vector<int>> mat1 = {{1, 5, 6},
                                {8, 10, 11},
                                {15, 16, 18}};
    vector<vector<int>> mat2 = {{2, 4, 7},
                                {9, 10, 12},
                                {13, 16, 20}};
    cout << obj.countPairs(mat1, mat2, n, x) << endl;

    n = 2, x = 10;
    mat1 = {{1, 2},
            {3, 4}};
    mat2 = {{4, 5},
            {6, 7}};
    cout << obj.countPairs(mat1, mat2, n, x) << endl;

    return 0;
}