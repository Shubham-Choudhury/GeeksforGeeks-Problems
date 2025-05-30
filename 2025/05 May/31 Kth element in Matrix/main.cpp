// Link: https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countSmallerEqual(const vector<vector<int>> &matrix, int x)
    {
        int n = matrix.size();
        int count = 0;
        int row = 0;
        int col = n - 1;

        while (row < n && col >= 0)
        {
            if (matrix[row][col] <= x)
            {
                count += (col + 1);
                row++;
            }
            else
            {
                col--;
            }
        }

        return count;
    }

    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        int ans = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int count = countSmallerEqual(matrix, mid);

            if (count < k)
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {
        {16, 28, 60, 64},
        {22, 41, 63, 91},
        {27, 50, 87, 93},
        {36, 78, 87, 94}};
    int k = 3;
    int result = sol.kthSmallest(matrix, k);
    cout << "The " << k << "th smallest element in the matrix is: " << result << endl;

    matrix = {{10, 20, 30, 40}, {15, 25, 35, 45}, {24, 29, 37, 48}, {32, 33, 39, 50}};
    k = 7;
    result = sol.kthSmallest(matrix, k);
    cout << "The " << k << "th smallest element in the matrix is: " << result << endl;

    return 0;
}